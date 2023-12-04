

/*
CODE OWNERSHIP AND DISCLAIMER OF LIABILITY

Microchip Technology Incorporated ("Microchip") retains all ownership and
intellectual property rights in the code accompanying this message and in all
derivatives hereto. You may use this code, and any derivatives created by any
person or entity by or on your behalf, exclusively with Microchip?s proprietary
products. Your acceptance and/or use of this code constitutes agreement to the
terms and conditions of this notice.

CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP?S PRODUCTS,
COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER
IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY),
STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT,
SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST
OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF
MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS
IN ANY WAY RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO
MICROCHIP SPECIFICALLY TO HAVE THIS CODE DEVELOPED.

You agree that you are solely responsible for testing the code and determining
its suitability.  Microchip has no obligation to modify, test, certify, or
support the code.


File description:
 Header file desccribing functions regarding unified drivers for RTCC devices
 across XC8 (v1.32), XC16 (v1.24) and XC32 (v1.30) compilers for PIC18s and up

Revision history:
 v1.0 - First revision, <month>, 2015

*/

#include "xc.h"
#include "I2C_RTCC_app.h"
#include "../mcc.h"
#include "../../main.h"
#include "../i2c1.h"

extern      tStatus     Status;
#define SLAVE_I2C_GENERIC_RETRY_MAX        100
#define SLAVE_I2C_GENERIC_DEVICE_TIMEOUT   150    // define slave timeout
#define I2C_RTCC_SRAM_ADDRESS             0x6F    ///<  7-bit device address for RTCC and SRAM
#define I2C_RTCC_EEPROM_ADDRESS           0x57    ///<  7-bit device address for EEPROM in RTCC
#define I2C_RTCC_EEPROM_STATUS            0xFF    ///<  STATUS REGISTER in the  EEPROM
	
    
ERR_STATUS_T I2C_RTCC_Reset();

ERR_STATUS_T I2C_RTCC_Initialize(void)
{
    uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    
    // Stop the crystal before writing the values to RTCC    
    status = I2C_RTCC_StopOscillator();
    while (oscillatorStatus)
    {
        status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
        if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    }
    
    // Set device register to initial values
    I2C_RTCC_Reset();
/*
    // Set initial date and time
    I2C_RTCC_YearSet(bin2bcd(20));
    I2C_RTCC_MonthSet(bin2bcd(1));
    I2C_RTCC_DateSet(bin2bcd(26));
    
    I2C_RTCC_SecondsSet(bin2bcd(0));
    I2C_RTCC_MinutesSet(bin2bcd(26));
    I2C_RTCC_HoursSet(bin2bcd(20));
 */
    I2C_RTCC_HourFormatSet(I2C_RTCC_HOUR_24);

   // Digital trimming functions
    I2C_RTCC_TrimValueSet(0);
    I2C_RTCC_PositiveTrimSignSet();
    I2C_RTCC_CoarseTrimDisable();
    
    // EEPROM  functions
    I2C_RTCC_EE_ArrayProtectNone();
    
    // General RTCC functions
    I2C_RTCC_BatteryBackupDisable();
    I2C_RTCC_StartOscillator();
	
    return status;
}

ERR_STATUS_T MCP794xx_Read( uint8_t address, uint8_t *pData, uint8_t nCount);         // PASSED
ERR_STATUS_T MCP794xx_Write( uint8_t address, uint8_t *pData, uint8_t nCount);        // PASSED


/**************************************************************************
 * Date-Time Functions
 **************************************************************************/

ERR_STATUS_T I2C_RTCC_HourFormatSet( uint8_t hourFormat)
{
    ERR_STATUS_T status;
    uint8_t aux=0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, &aux);    // get RTCHOUR register and write only hour format back
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= 0x3F;
    aux |= hourFormat;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCHOUR, aux);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_HourFormatGet( uint8_t *hourFormat)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, hourFormat);    // get RTCHOUR register and write only hour format back
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *hourFormat &= I2C_RTCC_HOUR_12;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_AMSet(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= 0x5F;     // keep all bits except ~AM/PM bit
        
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCHOUR, aux);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PMSet(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= 0x5F;            // keep all bits except ~AM/PM bit
    aux |= I2C_RTCC_PM; 
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCHOUR, aux);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_AMPMGet( uint8_t *AMPM)   // gets AMPM hour type
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, AMPM );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *AMPM &= I2C_RTCC_PM;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SecondsSet( uint8_t seconds )
{
    ERR_STATUS_T status;
    uint8_t aux = 0;

    seconds &= 0x7F;    // mask ST bit, also if the user sends an invalid value, they'll get ants in the RTCC
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCSEC, &aux );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCSEC, seconds | (aux & 0x80) );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MinutesSet(  uint8_t minutes )
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCMIN, minutes );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_HoursSet(  uint8_t hours )
{
    ERR_STATUS_T status;
    uint8_t hourFormat = 0, ampmBit = 0;
    
    status = I2C_RTCC_HourFormatGet( &hourFormat );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_AMPMGet( &ampmBit );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    if (hourFormat == I2C_RTCC_HOUR_12) 
    {
        hours &= 0x1F;      // RTCC is in 12 hours format
        status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCHOUR, hours | I2C_RTCC_HOUR_12 | ampmBit );
        if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    }
    else
    {
        hours &= 0x3F;      // RTCC is in 24 hours format, write only 6 bits of hours; it is users responsibility to check valid value
        status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCHOUR, hours | I2C_RTCC_HOUR_24);
        if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    }
    
    return status;
}

ERR_STATUS_T I2C_RTCC_DayOfWeekSet(  uint8_t dayOfWeek )
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= 0xF8;            // throw away WKDAYx bits
    dayOfWeek &= 0x07;     // keep only WKDAYx bits
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCWKDAY, dayOfWeek | aux );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_DateSet( uint8_t date)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCDATE, date );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MonthSet( uint8_t month)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCMONTH, month );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_YearSet( uint8_t year)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCYEAR, year );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SecondsGet( uint8_t *seconds)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCSEC, seconds);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *seconds &= 0x7F;   // mask ST bit
        
    return status;
}

ERR_STATUS_T I2C_RTCC_MinutesGet( uint8_t *minutes)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCMIN, minutes);
            
    return status;
   
}

ERR_STATUS_T I2C_RTCC_HoursGet( uint8_t *hours)
{
    ERR_STATUS_T status;
    uint8_t hourFormat = 0;
    
     status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCHOUR, hours);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    hourFormat = *hours & I2C_RTCC_HOUR_12;
    
    if (hourFormat == I2C_RTCC_HOUR_12) 
    {
        *hours &= 0x1F;      // RTCC is in 12 hours format
    }
    else
    {
        *hours &= 0x3F;      // RTCC is in 24 hours format, write only 6 bits of hours; it is users responsibility to check valid value
    }
    
    return status;
}

ERR_STATUS_T I2C_RTCC_DayOfWeekGet( uint8_t *dayOfWeek)
{
    ERR_STATUS_T status;
   
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, dayOfWeek);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;;    
    
    *dayOfWeek &= 0x07; 
   
    return status;
}

ERR_STATUS_T I2C_RTCC_DateGet( uint8_t *date)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCDATE, date);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MonthGet( uint8_t *month)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCMONTH, month);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;   
    
    *month &= 0x1F;      // keep only date bits;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_YearGet( uint8_t *year)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCYEAR, year);

    return status;
}


/**************************************************************************
 * Timestamp Functions
 **************************************************************************/
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampAMPMGet( uint8_t *AMPM)   // gets AMPM hour type
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRDNHOUR, AMPM );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *AMPM &= I2C_RTCC_PM;    
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerDownTimeStampMinutesGet( uint8_t *minutes)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_POWERDNMIN, minutes);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerDownTimeStampHoursGet( uint8_t *hours)
{
    ERR_STATUS_T status;
    uint8_t hourFormat = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRDNHOUR, hours);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    hourFormat = *hours & I2C_RTCC_HOUR_12;
    
    if (hourFormat == I2C_RTCC_HOUR_12) 
    {
        *hours &= 0x1F;      // RTCC is in 12 hours format
    }
    else
    {
        *hours &= 0x3F;      // RTCC is in 24 hours format, write only 6 bits of hours; it is users responsibility to check valid value
    }
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerDownTimeStampDayOfWeekGet( uint8_t *dayOfWeek)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRDNMTH, dayOfWeek);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *dayOfWeek >> 5;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerDownTimeStampDateGet( uint8_t *date)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRDNDATE, date);

        
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerDownTimeStampMonthGet( uint8_t *month)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRDNMTH, month);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *month &= 0x1F;
    
    return status;    
}


ERR_STATUS_T I2C_RTCC_PowerUpTimeStampAMPMGet( uint8_t *AMPM)   // gets AMPM hour type
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPHOUR, AMPM );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;

    *AMPM &= I2C_RTCC_PM;
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_PowerUpTimeStampMinutesGet( uint8_t *minutes)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPMIN, minutes);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_PowerUpTimeStampHoursGet( uint8_t *hours)
{
    ERR_STATUS_T status;
    uint8_t hourFormat = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPHOUR, hours);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    hourFormat = *hours & I2C_RTCC_HOUR_12;
    
    if (hourFormat == I2C_RTCC_HOUR_12) 
    {
        *hours &= 0x1F;      // RTCC is in 12 hours format
    }
    else
    {
        *hours &= 0x3F;      // RTCC is in 24 hours format, write only 6 bits of hours
    }
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerUpTimeStampDayOfWeekGet( uint8_t *dayOfWeek)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPMTH, dayOfWeek);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *dayOfWeek >> 5;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerUpTimeStampDateGet( uint8_t *date)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPDATE, date);
        
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerUpTimeStampMonthGet( uint8_t *month)
{
    ERR_STATUS_T status;

    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_PWRUPMTH, month);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *month &= 0x1F;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_PowerFailStatusGet( uint8_t *failStatus)
{
    ERR_STATUS_T status;
   
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, failStatus);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;;    
    
    *failStatus &= I2C_RTCC_PWRFAIL; 
   
    return status;
}
ERR_STATUS_T I2C_RTCC_PowerFailStatusClear(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    // a write to the I2C_RTCC_ADDR_RTCWKDAY is needed to clear the PWRFAIL flag
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCWKDAY, aux );
    
    return status;    
}

/**************************************************************************
 * Digital trimming Functions
 **************************************************************************/

ERR_STATUS_T I2C_RTCC_TrimValueSet( uint8_t value)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_OSCTRIM, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= I2C_RTCC_NEGATIVE_TRIM_SIGN;
    value &= 0x7F;      // discard 7th bit; it's used for sign
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_OSCTRIM, aux | value);
            
    return status;    
}

ERR_STATUS_T I2C_RTCC_TrimValueGet( uint8_t *value)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_OSCTRIM, value);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *value &= ~I2C_RTCC_NEGATIVE_TRIM_SIGN;
     
    return status;      
}

ERR_STATUS_T I2C_RTCC_PositiveTrimSignSet(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_OSCTRIM, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux |= I2C_RTCC_POSITIVE_TRIM_SIGN;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_OSCTRIM, aux );
            
    return status;       
}

ERR_STATUS_T I2C_RTCC_NegativeTrimSignSet(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_OSCTRIM, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= I2C_RTCC_NEGATIVE_TRIM_SIGN;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_OSCTRIM, aux );
            
    return status;   
}

ERR_STATUS_T I2C_RTCC_TrimSignGet( uint8_t *sign)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_OSCTRIM, sign);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *sign &= I2C_RTCC_POSITIVE_TRIM_SIGN;
    
    return status;
    
}

ERR_STATUS_T I2C_RTCC_CoarseTrimEnable(void)
{
    ERR_STATUS_T status;
    uint8_t controlByte;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &controlByte);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    controlByte |= I2C_RTCC_CRSTRIM;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, controlByte);
            
    return status;    
}

ERR_STATUS_T I2C_RTCC_CoarseTrimDisable(void)
{
    ERR_STATUS_T status;
    uint8_t controlByte;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &controlByte);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    controlByte &= ~I2C_RTCC_CRSTRIM;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, controlByte);
            
    return status;    
}

ERR_STATUS_T I2C_RTCC_CoarseTrimStatusGet( uint8_t *coarseTrimStatus)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, coarseTrimStatus);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;;    
    
    *coarseTrimStatus &= I2C_RTCC_CRSTRIM; 
    
    return status;   
}

/**************************************************************************
 * General Functions
 **************************************************************************/
ERR_STATUS_T I2C_RTCC_StartOscillator(void)
{
    ERR_STATUS_T status;
    uint8_t seconds = 0;
        
    status = I2C_RTCC_SecondsGet(&seconds);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    seconds |= I2C_RTCC_START_32KHZ;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCSEC, seconds);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_StopOscillator(void)
{
    ERR_STATUS_T status;
    uint8_t seconds=0;
    
    status = I2C_RTCC_SecondsGet( &seconds);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    seconds &= ~I2C_RTCC_START_32KHZ;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCSEC, seconds);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_STBitGet( uint8_t *STBit)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCSEC, STBit);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
     
    *STBit &= I2C_RTCC_START_32KHZ;   // keep only ST bit
    
    return status;
}

ERR_STATUS_T I2C_RTCC_OscillatorRunningGet( uint8_t *oscillatorStatus) //explain that if ST = 0 and EXTOSC = 1 we get clock pulses; it doesn't matter if we use crystal or external oscillator;
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, oscillatorStatus);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *oscillatorStatus &= I2C_RTCC_OSCRUN;     // return I2C_RTCC_OSCRUN;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_ExternalOscillatorStart(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp |= I2C_RTCC_EXTOSC;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_ExternalOscillatorStop(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= ~I2C_RTCC_EXTOSC;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_EXTOSCBitGet( uint8_t *EXTOSCBit)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, EXTOSCBit );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *EXTOSCBit &= I2C_RTCC_EXTOSC;
    
    return status;
}

    
    
ERR_STATUS_T I2C_RTCC_MFP32KHzSet(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= 0xFC;    
    temp |= I2C_RTCC_SQWFS_32K;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MFP8KHzSet(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;

    temp &= 0xFC;    
    temp |= I2C_RTCC_SQWFS_08K;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MFP4KHzSet(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= 0xFC;
    temp |= I2C_RTCC_SQWFS_04K;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_MFP1HzSet(void)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= 0xFC;
    temp |= I2C_RTCC_SQWFS_01H;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SquareWaveFrequencyGet( uint8_t *squareWaveFrequencyValue) //get values returned from datasheet
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, squareWaveFrequencyValue );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *squareWaveFrequencyValue &= I2C_RTCC_SQWFS_32K;
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SquareWaveEnable(void) // sets SQWEN bit in CONTROL register
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp |= I2C_RTCC_SQWEN;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SquareWaveDisable(void) // clears SQWEN bit in CONTROL register
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= ~I2C_RTCC_SQWEN;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SquareWaveStatusGet( uint8_t *squareWaveEnabled) // gets value of SQWEN bit in CONTROL register
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, squareWaveEnabled );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *squareWaveEnabled &= I2C_RTCC_SQWEN;
    
    return status;
}

    
    
ERR_STATUS_T I2C_RTCC_GPOEnable(void) //it ensures alarms & sq. wv. are disabled to allow MFP to be used as GPO according to OUT bit value
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= 0x0F;           // disable alarms and SQWEN
    temp |= I2C_RTCC_OUT ;  // enable OUT
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp  );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_GPODisable(void) // clears OUT bit without changing other bits in register
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= ~I2C_RTCC_OUT;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp );
    
    return status;
}

    
ERR_STATUS_T I2C_RTCC_SetOUTBitHigh(void)    // functions only write to OUT bit (DO NOT DISABLE alarms or sqwv)
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp |= I2C_RTCC_OUT ;  // enable OUT
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp  );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_SetOUTBitLow(void)     //       --------------------------------------------------
{
    ERR_STATUS_T status;
    uint8_t temp = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_CONTROL, &temp );
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    temp &= ~I2C_RTCC_OUT ;  // disable OUT
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, temp  );
    
    return status;
}


ERR_STATUS_T I2C_RTCC_BatteryBackupEnable(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux |= I2C_RTCC_VBATEN;            

    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCWKDAY, aux );
    
    return status;
}

ERR_STATUS_T I2C_RTCC_BatteryBackupDisable(void)
{
    ERR_STATUS_T status;
    uint8_t aux = 0;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, &aux);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    aux &= ~I2C_RTCC_VBATEN;            

    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCWKDAY, aux );
    
    return status;    
}


ERR_STATUS_T I2C_RTCC_BatteryBackupGet( uint8_t *bateryBackupEnabled)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCWKDAY, bateryBackupEnabled);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *bateryBackupEnabled &= I2C_RTCC_VBATEN;            

    return status;
}

    
ERR_STATUS_T I2C_RTCC_LeapYearGet( uint8_t *isLeapYear)
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteRead( I2C_RTCC_ADDR_RTCMONTH, isLeapYear);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *isLeapYear &= I2C_RTCC_LEAP_YEAR;            

        
    return status;
}


ERR_STATUS_T I2C_RTCC_ByteWrite(uint8_t address, uint8_t data )
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL ;
    
    status = MCP794xx_Write( address, &data, 1);

    return status;
}

ERR_STATUS_T I2C_RTCC_ByteRead(uint8_t address, uint8_t *data )
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL ;

    status = MCP794xx_Read( address, data, 1);
    
    return status;
}    

/**************************************************************************
 * EEPROM functions
 **************************************************************************/
ERR_STATUS_T I2C_RTCC_EE_UnlockSequence(void)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    uint8_t unlockBytes[2] = {0x55, 0xAA};
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_ADDR_EEUNLOCK, 1, unlockBytes);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_ADDR_EEUNLOCK, 1, unlockBytes+1);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;    
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_ArrayProtectNone(void)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    uint8_t blockProtectValue = 0x00;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_EEPROM_STATUS, 1, &blockProtectValue);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_ArrayProtectQuarter(void)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    uint8_t blockProtectValue = 0x04;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_EEPROM_STATUS, 1, &blockProtectValue);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_ArrayProtectHalf(void)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    uint8_t blockProtectValue = 0x08;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_EEPROM_STATUS, 1, &blockProtectValue);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_ArrayProtectAll(void)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    uint8_t blockProtectValue = 0x0C;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_EEPROM_STATUS, 1, &blockProtectValue);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_StatusRegisterGet( uint8_t *statusRegister)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    
    status = I2C_RTCC_EE_DataRead( I2C_RTCC_EEPROM_STATUS, 1, statusRegister);
    
    return status;
}

ERR_STATUS_T I2C_RTCC_EE_StatusRegisterSet( uint8_t statusRegister)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    
    status = I2C_RTCC_EE_DataWrite( I2C_RTCC_EEPROM_STATUS, 1, &statusRegister);
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_BlockProtectGet( uint8_t *blockProtectValue)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
    
    status = I2C_RTCC_EE_DataRead( I2C_RTCC_EEPROM_STATUS, 1, blockProtectValue);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    *blockProtectValue &= 0x0C;
    *blockProtectValue = *blockProtectValue >> 2;
    
    return status;    
}

ERR_STATUS_T I2C_RTCC_EE_DataWrite( uint8_t address, uint8_t length, uint8_t *data)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL, *pstatus = &status;
    uint8_t     writeBuffer[9], *pD, counter;
    int32_t     timeOut = _XTAL_FREQ / 100;

    pD = data;
    writeBuffer[0] = address;
    if (length <= 8)
    {
        for ( counter = 1; counter <= length; counter++)
        {
            writeBuffer[counter] = pD[counter-1];
        }

        I2C1_MasterWrite( writeBuffer, length+1, I2C_RTCC_EEPROM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus );
        if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;
    }
    else 
        return status;
    
    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };
    
    return status;
}

ERR_STATUS_T I2C_RTCC_EE_DataRead( uint8_t address, uint8_t length, uint8_t *data)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL, *pstatus = &status;
    uint8_t     writeBuffer[9];
    int32_t     timeOut = _XTAL_FREQ / 100;
    
    writeBuffer[0] = address;
    
    if (length <= 8)
    {
    // write to the selected bus

        I2C1_MasterWrite( writeBuffer, 1, I2C_RTCC_EEPROM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus );
        if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;
    }
    else
        return status;
    
    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };
     
    timeOut = _XTAL_FREQ / 100;
    
    // read from the selected bus

    I2C1_MasterRead( data, length, I2C_RTCC_EEPROM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus);
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;

    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };

    return status;    
}

/**************************************************************************
 * Other functions
 **************************************************************************/

uint8_t bin2bcd(uint8_t value)
{
    return ( ((value / 10) << 4) + (value % 10) );
}

uint8_t bcd2bin(uint8_t value)
{
    return ( ((value & 0xF0) >> 4) * 10 + (value & 0x0F) );
}

//------------------------------------------------------------------------------
ERR_STATUS_T MCP794xx_Read_nCount(uint8_t address, uint8_t *pData,  uint8_t nCount)
{
    ERR_STATUS_T status = 0, *pstatus = &status;
    uint8_t     writeBuffer[3];
    int32_t     timeOut = _XTAL_FREQ / 100;
    
    writeBuffer[0] = address;
    
    // write to the selected bus

    I2C1_MasterWrite( writeBuffer, 1, I2C_RTCC_SRAM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus );
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;

    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };
     
    timeOut = _XTAL_FREQ / 100;
    
    // read from the selected bus
    
    I2C1_MasterRead( pData, nCount, I2C_RTCC_SRAM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus);
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;

    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };

    return status;
}
//------------------------------------------------------------------------------
ERR_STATUS_T MCP794xx_Read(uint8_t address, uint8_t *pData,  uint8_t nCount)
{
    ERR_STATUS_T status = 0, *pstatus = &status;
    uint8_t     writeBuffer[3];
    int32_t     timeOut = _XTAL_FREQ / 100;
    
    writeBuffer[0] = address;
    
    // write to the selected bus

    I2C1_MasterWrite( writeBuffer, 1, I2C_RTCC_SRAM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus );
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;

    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };
     
    timeOut = _XTAL_FREQ / 100;
    
    // read from the selected bus
    
    I2C1_MasterRead( pData, 1, I2C_RTCC_SRAM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus);
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;

    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };

    return status;
}
                

ERR_STATUS_T MCP794xx_Write(uint8_t address, uint8_t *pData, uint8_t nCount)
{
    ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL, *pstatus = &status;
    uint8_t     writeBuffer[3], *pD;
    int32_t     timeOut = _XTAL_FREQ / 100;

    pD = pData;
    writeBuffer[0] = address;
    writeBuffer[1] = *pD;


    I2C1_MasterWrite( writeBuffer, 2, I2C_RTCC_SRAM_ADDRESS, (I2C1_MESSAGE_STATUS*)pstatus );
    if ((I2C1_MESSAGE_STATUS)status == I2C1_MESSAGE_FAIL) return status;
 
    while ( (status != ERR_I2C_MESSAGE_COMPLETE ) && (timeOut > 0) )
    {
        switch (status)
        {
            case ERR_I2C_MESSAGE_FAIL:
            case ERR_I2C_MESSAGE_ADDRESS_NO_ACK:
            case ERR_I2C_DATA_NO_ACK: return status;
            default: --timeOut ;
        }
    };
    
    return status;
}

ERR_STATUS_T I2C_RTCC_Reset()
{
    ERR_STATUS_T status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_RTCWKDAY, 0x01);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_CONTROL, 0x80);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_OSCTRIM, 0x00);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_ALM0WKDAY, 0x01);
    if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
    
    status = I2C_RTCC_ByteWrite( I2C_RTCC_ADDR_ALM1WKDAY, 0x01);
    
    return status;
}
//------------------------------------------------------------------------------
uint8_t read_DateTime(void)
{
  ERR_STATUS_T status;
  uint8_t   error_code= 0;
  unsigned char     tab[4];
  
  status= MCP794xx_Read_nCount(0x00, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    }
  tab[0]= tab[0] & 0b01111111;
  tab[0]= bcd2bin(tab[0]);
  Status.DateTime.hour.seconds= tab[0];
  
   status= MCP794xx_Read_nCount(0x01, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    }
  tab[0]= tab[0] & 0b01111111;
  tab[0]= bcd2bin(tab[0]);
  Status.DateTime.hour.minutes= tab[0]; 
  
  status= MCP794xx_Read_nCount(0x02, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    }
  tab[0]= tab[0] & 0b00111111;
  tab[0]= bcd2bin(tab[0]);
  Status.DateTime.hour.hours= tab[0];
  
  status= MCP794xx_Read_nCount(0x03, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    } 
  Status.DateTime.date.wkDay= tab[0] & 0b111;
  
  status= MCP794xx_Read_nCount(0x04, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    } 
  Status.DateTime.date.day= bcd2bin(tab[0] & 0b111111);

  status= MCP794xx_Read_nCount(0x05, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    } 
  Status.DateTime.date.month= bcd2bin(tab[0] & 0b11111);  
  
  status= MCP794xx_Read_nCount(0x06, tab, 1);
  if (status != ERR_I2C_MESSAGE_COMPLETE ) 
    {  
        error_code= 0x00;
        return error_code;
    } 
  Status.DateTime.date.year= bcd2bin(tab[0] & 0xFF);
  return 0x01;
}//END:
//------------------------------------------------------------------------------

