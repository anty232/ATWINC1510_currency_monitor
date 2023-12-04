/**
@copyright 
CODE OWNERSHIP AND DISCLAIMER OF LIABILITY\n
Microchip Technology Incorporated ("Microchip") retains all ownership and
intellectual property rights in the code accompanying this message and in all
derivatives hereto. You may use this code, and any derivatives created by any
person or entity by or on your behalf, exclusively with Microchip?s proprietary
products. Your acceptance and/or use of this code constitutes agreement to the
terms and conditions of this notice.\n
CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP?S PRODUCTS,
COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.\n
YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER
IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY),
STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT,
SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST
OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF
MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS
IN ANY WAY RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO
MICROCHIP SPECIFICALLY TO HAVE THIS CODE DEVELOPED.\n
You agree that you are solely responsible for testing the code and determining
its suitability.  Microchip has no obligation to modify, test, certify, or
support the code.
    
@file I2C_RTCC_app.h
    
@brief Header file desccribing functions regarding unified drivers for RTCC devices
 across XC8 and XC16 compilers for MCC supported PIC MCUs.

@version API Version       :  1.0
*/

#ifndef MCP79XXX_H
#define	MCP79XXX_H

#include <stdint.h>
#include <time.h>


/**************************************************************************
 * I2C RTCC CONSTANTS
 *************************************************************************/

    #define  I2C_RTCC_ADDR_RTCSEC       0x00        ///<  address of SECONDS      register
    #define  I2C_RTCC_ADDR_RTCMIN       0x01        ///<  address of MINUTES      register
    #define  I2C_RTCC_ADDR_RTCHOUR      0x02        ///<  address of HOURS        register
    #define  I2C_RTCC_ADDR_RTCWKDAY     0x03        ///<  address of DAY OF WK    register
    #define  I2C_RTCC_ADDR_STAT         0x03        ///<  address of STATUS       register
    #define  I2C_RTCC_ADDR_RTCDATE      0x04        ///<  address of DATE         register
    #define  I2C_RTCC_ADDR_RTCMONTH     0x05        ///<  address of MONTH        register
    #define  I2C_RTCC_ADDR_RTCYEAR      0x06        ///<  address of YEAR         register
    #define  I2C_RTCC_ADDR_CONTROL      0x07        ///<  address of CONTROL      register
    #define  I2C_RTCC_ADDR_OSCTRIM      0x08        ///<  address of CALIB        register
    #define  I2C_RTCC_ADDR_EEUNLOCK     0x09        ///<  address of UNLOCK ID    register

    #define  I2C_RTCC_ADDR_ALM0SEC      0x0A        ///<  address of ALARMO SEC   register
    #define  I2C_RTCC_ADDR_ALM0MIN      0x0B        ///<  address of ALARMO MIN   register
    #define  I2C_RTCC_ADDR_ALM0HOUR     0x0C        ///<  address of ALARMO HOUR  register
    #define  I2C_RTCC_ADDR_ALM0WKDAY    0x0D        ///<  address of ALARM0 CONTR register
    #define  I2C_RTCC_ADDR_ALM0DATE     0x0E        ///<  address of ALARMO DATE  register
    #define  I2C_RTCC_ADDR_ALM0MTH      0x0F        ///<  address of ALARMO MONTH register

    #define  I2C_RTCC_ADDR_ALM1SEC      0x11        ///<  address of ALARM1 SEC   register
    #define  I2C_RTCC_ADDR_ALM1MIN      0x12        ///<  address of ALARM1 MIN   register
    #define  I2C_RTCC_ADDR_ALM1HOUR     0x13        ///<  address of ALARM1 HOUR  register
    #define  I2C_RTCC_ADDR_ALM1WKDAY    0x14        ///<  address of ALARM1 CONTR register
    #define  I2C_RTCC_ADDR_ALM1DATE     0x15        ///<  address of ALARM1 DATE  register
    #define  I2C_RTCC_ADDR_ALM1MTH      0x16        ///<  address of ALARM1 MONTH register
       
    #define  I2C_RTCC_ADDR_POWERDNMIN   0x18        ///<  address of T_SAVER MIN(VDD->BAT)
    #define  I2C_RTCC_ADDR_PWRDNHOUR    0x19        ///<  address of T_SAVER HR (VDD->BAT)
    #define  I2C_RTCC_ADDR_PWRDNDATE    0x1A        ///<  address of T_SAVER DAT(VDD->BAT)
    #define  I2C_RTCC_ADDR_PWRDNMTH     0x1B        ///<  address of T_SAVER MTH(VDD->BAT)

    #define  I2C_RTCC_ADDR_PWRUPMIN     0x1C        ///<  address of T_SAVER MIN(BAT->VDD)
    #define  I2C_RTCC_ADDR_PWRUPHOUR    0x1D        ///<  address of T_SAVER HR (BAT->VDD)
    #define  I2C_RTCC_ADDR_PWRUPDATE    0x1E        ///<  address of T_SAVER DAT(BAT->VDD)
    #define  I2C_RTCC_ADDR_PWRUPMTH     0x1F        ///<  address of T_SAVER MTH(BAT->VDD)

/**************************************************************************
 *                  GLOBAL CONSTANTS RTCC - INITIALIZATION
 *************************************************************************/
 
    #define  I2C_RTCC_OUT                 0x80        ///<  = b7 (ADDR_CONTROL)
    #define  I2C_RTCC_SQWEN               0x40        ///<  SQWE = b6 (ADDR_CTROL)
    #define  I2C_RTCC_EXTOSC              0X08        ///<  External oscillator start bit;
    #define  I2C_RTCC_ALM_NO              0x00        ///<  no alarm activated        (ADDR_CONTROL)
    #define  I2C_RTCC_ALM_0               0x10        ///<  ALARM0 is       activated (ADDR_CONTROL)
    #define  I2C_RTCC_ALM_1               0x20        ///<  ALARM1 is       activated (ADDR_CONTROL)
    #define  I2C_RTCC_ALM_01              0x30        ///<  both alarms are activated (ADDR_CONTROL)
    #define  I2C_RTCC_SQWFS_01H           0x00        ///<  MFP = SQVAW(01 HERZ)      (ADDR_CONTROL)
    #define  I2C_RTCC_SQWFS_04K           0x01        ///<  MFP = SQVAW(04 KHZ)       (ADDR_CONTROL)
    #define  I2C_RTCC_SQWFS_08K           0x02        ///<  MFP = SQVAW(08 KHZ)       (ADDR_CONTROL)
    #define  I2C_RTCC_SQWFS_32K           0x03        ///<  MFP = SQVAW(32 KHZ)       (ADDR_CONTROL)
    #define  I2C_RTCC_CRSTRIM             0x04        ///<  MFP = SQVAW(64 HERZ)      (ADDR_CONTROL)
    #define  I2C_RTCC_ALMx_POL            0x80        ///<  polarity of MFP on alarm  (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_SEC           0x00        ///<  ALARM compare on SEC      (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_MIN           0x10        ///<  ALARM compare on MIN      (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_HOUR          0x20        ///<  ALARM compare on HOUR     (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_DAY           0x30        ///<  ALARM compare on DAY      (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_DATE          0x40        ///<  ALARM compare on DATE     (ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMxC_ALL           0x70        ///<  ALARM compare on all param(ADDR_ALMxCTL)
    #define  I2C_RTCC_ALMx_IF             0x08        ///<  MASK of the ALARM_IF      (ADDR_ALMxCTL)
    #define  I2C_RTCC_OSCRUN              0x20        ///<  state of the oscillator running
    #define  I2C_RTCC_VBATEN              0x08        ///<  enable battery for back-up
    #define  I2C_RTCC_START_32KHZ         0x80        ///<  start crystal: ST = b7 (ADDR_SEC)
    #define  I2C_RTCC_LEAP_YEAR           0x20        ///<  mask for the leap year bit(MONTH REG)
    #define  I2C_RTCC_HOUR_12             0x40        ///<  12 hours format   (ADDR_HOUR)
    #define  I2C_RTCC_HOUR_24             0x00        ///<  24 hour format
    #define  I2C_RTCC_AM                  0x00        ///<  post-meridian bit (ADDR_HOUR)
    #define  I2C_RTCC_PM                  0x20        ///<  post-meridian bit (ADDR_HOUR)
    #define  I2C_RTCC_PWRFAIL             0x10        ///<  VBAT bit in register I2C_RTCC_ADDR_RTCWKDAY
    #define  I2C_RTCC_POSITIVE_TRIM_SIGN  0X80        ///<  Negative sign value
    #define  I2C_RTCC_NEGATIVE_TRIM_SIGN  0X7F        ///<  Positive sign value

typedef enum
{
    ERR_I2C_MESSAGE_FAIL,           
    ERR_I2C_MESSAGE_PENDING,        
    ERR_I2C_MESSAGE_COMPLETE,       
    ERR_I2C_STUCK_START,            
    ERR_I2C_MESSAGE_ADDRESS_NO_ACK, 
    ERR_I2C_DATA_NO_ACK,            
    ERR_I2C_LOST_STATE              
} ERR_STATUS_T;
    /** @enum I2C_RTCC_BUSES
     * User selectable I2C channels.
     */
typedef enum 
{
    MSSP1_I2C, 
    I2C, 
    I2C1, 
    I2C2, 
    I2C3
} I2C_RTCC_BUSES;


/** @struct I2C_RTCC
  * Defines an RTCC device.
 */
typedef struct
{
    I2C_RTCC_BUSES bus; ///< I2C channel used to communicate with the device
} I2C_RTCC;
/*
 
 */
uint8_t read_DateTime(void);
/**
 * Initializes the device using settings selected in the GUI.
 * @return an ERR_STATUS_T value
 * @sa ERR_STATUS_T
 */
ERR_STATUS_T I2C_RTCC_Initialize(void);

/**************************************************************************
 * Date-Time Functions
 *************************************************************************/
/**
 * Changes the mode to either 12-hour or 24-hour format.
 * @param hourFormat :uint8_t variable that needs to be either I2C_RTCC_HOUR_12 or I2C_RTCC_HOUR_24
 * @return an ERR_STATUS_T value
 * @sa ERR_STATUS_T
 * 
 * Example Usage:
 * @code
 * ERR_STATUS_T status;
 * uint8_t hourFormat = I2C_RTCC_HOUR_12;
 * status = I2C_RTCC_HourFormatSet(hourFormat);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_HourFormatSet( uint8_t hourFormat);    // PASSED

/**
 * Reads the hour format.
 * @param [out] *hourFormat Pointer to uint8_t variable that will be either I2C_RTCC_HOUR_12 or I2C_RTCC_HOUR_24 on successful read.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage:
 * @code
 * ERR_STATUS_T status;
 * uint8_t hourFormat;
 * status = I2C_RTCC_HourFormatGet(&hourFormat);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_HourFormatGet( uint8_t *hourFormat);   // PASSED

/**
 * Sets the period of the hour to AM.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_AMSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_AMSet(void);                                // PASSED

/**
 * Sets the period of the hour to PM.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_PMSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PMSet(void);                                // PASSED

/**
 * Gets the period of the hour.
 * @param [out] *AMPM Pointer to uint8_t variable that will be either I2C_RTCC_AM or I2C_RTCC_PM on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t ampmBit = 0;
 * status = I2C_RTCC_AMPMGet( &ampmBit );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_AMPMGet( uint8_t *AMPM);   // gets AMPM hour type  // PASSED

/**
 * Sends the Seconds value to the device.
 * @param [in] seconds uint8_t variable in BCD format, representing the value of the SECONDS
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Seconds to "14"
 * status = I2C_RTCC_SecondsSet(0x14);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_SecondsSet( uint8_t seconds);          // PASSED

/**
 * Sends the MINUTES value to the device.
 * @param [in] minutes uint8_t variable in BCD format, representing the value of the MINUTES
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Minutes to "14"
 * status = I2C_RTCC_MinutesSet(0x14);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_MinutesSet( uint8_t minutes);          // PASSED

/**
 * Sends the HOURS value to the device.
 * @param [in] hours uint8_t variable in BCD format, representing the value of the HOURS
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL;
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Hours to "14"
 * status = I2C_RTCC_HourFormatSet(I2C_RTCC_HOUR_24);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * status = I2C_RTCC_HoursSet(0x14);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * // ...
 * @endcode
 * \n
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL; 
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Hours to "2 pm"
 * status = I2C_RTCC_HourFormatSet(I2C_RTCC_HOUR_12);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * status = I2C_RTCC_PMSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * status = I2C_RTCC_HoursSet(0x2);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status; 
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_HoursSet( uint8_t hours);              // PASSED

/**
 * Sends the Day of Week value to the device.
 * @param [in] dayOfWeek uint8_t variable in BCD format, representing the day of the week
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL; 
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Day of Week to "3"
 * status = I2C_RTCC_DayOfWeekSet( 0x3);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_DayOfWeekSet( uint8_t dayOfWeek);      // PASSED

/**
 * Sends the DATE value to the device.
 * @param [in] date uint8_t variable in BCD format, representing the value of the current DATE
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL; 
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Date to "10"
 * status = I2C_RTCC_DateSet( 0x10);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_DateSet( uint8_t date);                // PASSED

/**
 * Sends the MONTH value to the device.
 * @param [in] month uint8_t variable in BCD format, representing the value of the current MONTH
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL; 
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Month to "10"
 * status = I2C_RTCC_MonthSet(0x10);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_MonthSet( uint8_t month);              // PASSED

/**
 * Sends the YEAR value to the device.
 * @param [in] year uint8_t variable in BCD format, representing the value of the current YEAR
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * ERR_STATUS_T status = ERR_I2C_MESSAGE_FAIL; 
 *  // Stop the crystal before writing the values to RTCC    
 * status = I2C_RTCC_StopOscillator();
 * while (oscillatorStatus)
 * {
 *     status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *     if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * }
 * // Set Year to "16"
 * status = I2C_RTCC_YearSet(0x16);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_YearSet( uint8_t year);                // PASSED

/**
 * Gets the value of the Seconds.
 * @param [out] *seconds Pointer to uint8_t variable that will get the Seconds value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t seconds = 0;
 * status = I2C_RTCC_SecondsGet( &seconds );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_SecondsGet( uint8_t *seconds);         // PASSED

/**
 * Gets the value of the Minutes.
 * @param [out] *minutes Pointer to uint8_t variable that will get the Minutes value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t minutes = 0;
 * status = I2C_RTCC_MinutesGet( &minutes );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_MinutesGet( uint8_t *minutes);         // PASSED

/**
 * Gets the value of the Hours.
 * @param [out] *hours Pointer to uint8_t variable that will get the Hours value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t hours = 0;
 * status = I2C_RTCC_HoursGet( &hours );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_HoursGet( uint8_t *hours);             // PASSED

/**
 * Gets the value of the Day of Week.
 * @param [out] *dayOfWeek Pointer to uint8_t variable that will get the Day of Week value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dayOfWeek = 0;
 * status = I2C_RTCC_DayOfWeekGet( &dayOfWeek );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_DayOfWeekGet( uint8_t *dayOfWeek);     // PASSED

/**
 * Gets the value of the Date.
 * @param [out] *date Pointer to uint8_t variable that will get the Date value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t date = 0;
 * status = I2C_RTCC_DateGet( &date );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_DateGet( uint8_t *date);               // PASSED

/**
 * Gets the value of the Month.
 * @param [out] *month Pointer to uint8_t variable that will get the Month value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t month = 0;
 * status = I2C_RTCC_MonthGet( &month );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_MonthGet( uint8_t *month);             // PASSED

/**
 * Gets the value of the Year.
 * @param [out] *year Pointer to uint8_t variable that will get the Year value on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t year = 0;
 * status = I2C_RTCC_YearGet( &year );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_YearGet( uint8_t *year);               // PASSED



/**************************************************************************
 * Timestamp Functions
 **************************************************************************/
/**
 * Gets the period timestamp hour for the power-down event.
 * @param [out] *AMPM Pointer to uint8_t variable that will be either I2C_RTCC_AM or I2C_RTCC_PM on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage:
 * @code
 * ERR_STATUS_T status;
 * uint8_t ampmBit;
 * status = I2C_RTCC_PowerDownTimeStampAMPMGet(&ampmBit);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampAMPMGet( uint8_t *AMPM);   // gets AMPM hour type    // PASSED

/**
 * Gets the Minutes value for the power-down event.
 * @param [out] *minutes Pointer to uint8_t variable that will get Minutes value from PWRDNMIN register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t minutesDown;
 * status = I2C_RTCC_PowerDownTimeStampMinutesGet( &minutesDown );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampMinutesGet( uint8_t *minutes);   // PASSED

/**
 * Gets the Hour value for the power-down event.
 * @param [out] *hours Pointer to uint8_t variable that will get Hour value from PWRDNHOUR register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t hoursDown;
 * status = I2C_RTCC_PowerDownTimeStampHoursGet( &hoursDown );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampHoursGet( uint8_t *hours);       // PASSED

/**
 * Gets the Date value for the power-down event.
 * @param [out] *date Pointer to uint8_t variable that will get Date value from PWRDNDATE register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dateDown;
 * status = I2C_RTCC_PowerDownTimeStampHoursGet( &dateDown );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampDateGet( uint8_t *date);         // PASSED

/**
 * Gets the Month value for the power-down event.
 * @param [out] *month Pointer to uint8_t variable that will get Month value from PWRDNMTH register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t monthDown;
 * status = I2C_RTCC_PowerDownTimeStampMonthGet( &monthDown );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerDownTimeStampMonthGet( uint8_t *month);       // PASSED


/**
 * Gets the period timestamp hour for the power-up event.
 * @param [out] *AMPM Pointer to uint8_t variable that will be either I2C_RTCC_AM or I2C_RTCC_PM on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage:
 * @code
 * ERR_STATUS_T status;
 * uint8_t ampmBit;
 * status = I2C_RTCC_PowerUpTimeStampAMPMGet(&ampmBit);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerUpTimeStampAMPMGet( uint8_t *AMPM);   // gets AMPM hour type      // PASSED

/**
 * Gets the Minutes value for the power-up event.
 * @param [out] *minutes Pointer to uint8_t variable that will get Minutes value from PWRUPMIN register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t minutesUp;
 * status = I2C_RTCC_PowerDownTimeStampMinutesGet( &minutesUp );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerUpTimeStampMinutesGet( uint8_t *minutes);     // PASSED

/**
 * Gets the Hour value for the power-up event.
 * @param [out] *hours Pointer to uint8_t variable that will get Hour value from PWRUPHOUR register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t hoursUp;
 * status = I2C_RTCC_PowerDownTimeStampHoursGet( &hoursUp );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerUpTimeStampHoursGet( uint8_t *hours);         // PASSED

/**
 * Gets the Date value for the power-up event.
 * @param [out] *date Pointer to uint8_t variable that will get Date value from PWRUPDATE register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dateUp;
 * status = I2C_RTCC_PowerUpTimeStampDateGet( &dateUp);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerUpTimeStampDateGet( uint8_t *date);           // PASSED

/**
 * Gets the Month value for the power-up event.
 * @param [out] *month Pointer to uint8_t variable that will get Month value from PWRUPMTH register on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t monthUp;
 * status = I2C_RTCC_PowerUpTimeStampMonthGet( &monthUp );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerUpTimeStampMonthGet( uint8_t *month);         // PASSED


/**
 * Indicates whether the device recovered from a power-cycle.
 * @param [out] *status Pointer to uint8_t variable that will be either I2C_RTCC_PWRFAIL or 0 (zero) on successful read
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t event;
 * status = I2C_RTCC_PowerFailStatusGet( &event );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerFailStatusGet( uint8_t *status);              // PASSED

/**
 * Clears the flag indicating a power-loss event. By doing this, the time-stamp registers get cleared as well.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t event;
 * status = I2C_RTCC_PowerFailStatusClear();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PowerFailStatusClear(void);                             // PASSED


/**************************************************************************
 * Digital trimming Functions
 **************************************************************************/
/**
 * Sets the rate at which clock pulses are to be added or subtracted from the oscillator input.
 * @param [in] value 7-bit value that for each step adds or removes 2 clock cycles from 32.768 KHz clock signal.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t rate;
 * status = I2C_RTCC_TrimValueSet( rate );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_TrimValueSet( uint8_t value);          // PASSED

/**
 * Gets the rate at which clock pulses are to be added or subtracted from the oscillator input.
 * @param [out] *value 7-bit value that for each step adds or removes 2 clock cycles from 32.768 KHz clock signal.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t rate;
 * status = I2C_RTCC_TrimValueSet( &rate );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_TrimValueGet( uint8_t *value);         // PASSED

/**
 * Removes clock cycles by two times the value of the Trim rate.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_NegativeTrimSignSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_NegativeTrimSignSet(void);                  // PASSED

/**
 * Adds clock cycles by two times the value of the Trim rate.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_PositiveTrimSignSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_PositiveTrimSignSet(void);                  // PASSED

/**
 * Shows the way Trim rate is used.
 * @param [out] *sign Pointer to uint8_t value that can be I2C_RTCC_POSITIVE_TRIM_SIGN for adding clocks, or 0 (zero) for subtracting clocks, on successful read.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t trimSign;
 * status = I2C_RTCC_TrimSignGet( &trimSign );
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_TrimSignGet( uint8_t *sign);           // PASSED


/**
 * Enabling coarse trimming adds or subtracts clock cycles 128 times per second based on Trim value and Sign.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_CoarseTrimEnable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_CoarseTrimEnable(void);                     // PASSED

/**
 * Disabling coarse trimming adds or subtracts clock cycles every minute based on Trim value and Sign.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_CoarseTrimDisable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_CoarseTrimDisable(void);                    // PASSED

/**
 * Indicates whether the Trim rate is applied every minute or 128 times per second.
 * @param [out] *status Pointer to uint8_t value. On successful read, it can be I2C_RTCC_CRSTRIM for high speed trimming or 0 (zero) for slow trimming.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t coarseTrimStatus;
 * status = I2C_RTCC_CoarseTrimStatusGet(&coarseTrimStatus);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_CoarseTrimStatusGet( uint8_t *status); // PASSED

/**************************************************************************
 * General RTCC functions
 **************************************************************************/
/**
 * Starts the internal oscillator.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_StartOscillator();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_StartOscillator(void);                      // PASSED

/**
 * Stop the internal oscillator.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t oscillatorStatus = I2C_RTCC_OSCRUN;
 * status = I2C_RTCC_StopOscillator();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // wait for the oscillator to stop
 * while (oscillatorStatus)
 *  {
 *      status = I2C_RTCC_OscillatorRunningGet(&oscillatorStatus);
 *      if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 *  }
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_StopOscillator(void);                       // PASSED

/**
 * Shows if the oscillator is started. It doesn't show if the oscillator is running yet.
 * @param [out] *STBit Pointer to uint8_t. On successful read, it can be I2C_RTCC_START_32KHZ or 0 (zero).
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t oscillatorStarted;
 * status = I2C_RTCC_STBitGet(&oscillatorStarted);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_STBitGet( uint8_t *STBit);             // PASSED

/**
 * Shows if the oscillator is running. This flag indicates a 32.768 KHz signal comes on X1 pin, that could be either from a crystal, or from an external oscillator.
 * @param [out] *oscillatorStatus Pointer to uint8_t. On successful read, it can be I2C_RTCC_OSCRUN or 0 (zero).
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t oscillatorRunning;
 * status = I2C_RTCC_OscillatorRunningGet(&oscillatorRunning);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_OscillatorRunningGet( uint8_t *oscillatorStatus); // PASSED   

/**
 * Enable input from an external oscillator.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_ExternalOscillatorStart();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_ExternalOscillatorStart(void);              // PASSED

/**
 * Disable input from an external oscillator.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_ExternalOscillatorStop();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_ExternalOscillatorStop(void);               // PASSED

/**
 * Shows if the input from an external oscillator is enabled. It doesn't show if the signal is being used yet.
 * @param [out] *EXTOSCBit Pointer to uint8_t. On successful read, it can be I2C_RTCC_EXTOSC or 0 (zero).
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t oscillatorStarted;
 * status = I2C_RTCC_EXTOSCBitGet(&oscillatorStarted);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EXTOSCBitGet( uint8_t *EXTOSCBit);     // PASSED


    
/**
 * Configures the MFP pin to output the undivided signal from the oscillator, which should be roughly 32.768 KHz. It doesn't enable the output.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_MFP32KHzSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 * @sa I2C_RTCC_SquareWaveEnable
 */
ERR_STATUS_T I2C_RTCC_MFP32KHzSet(void);                          // PASSED

/**
 * Configures the MFP pin to output a divided signal from the oscillator, which should be roughly 8 KHz. It doesn't enable the output.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_MFP8KHzSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 * @sa I2C_RTCC_SquareWaveEnable
 */
ERR_STATUS_T I2C_RTCC_MFP8KHzSet(void);                           // PASSED

/**
 * Configures the MFP pin to output a divided signal from the oscillator, which should be roughly 4 KHz. It doesn't enable the output.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_MFP4KHzSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 * @sa I2C_RTCC_SquareWaveEnable
 */
ERR_STATUS_T I2C_RTCC_MFP4KHzSet (void);                           // PASSED

/**
 * Configures the MFP pin to output a divided signal from the oscillator, which should be roughly 1 Hz. It doesn't enable the output.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_MFP1HzSet();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 * @sa I2C_RTCC_SquareWaveEnable
 */
ERR_STATUS_T I2C_RTCC_MFP1HzSet (void);                            // PASSED

/**
 * Gets a code representing the value of the frequency of the signal coming out from the MFP pin.
 * @param [out] *squareWaveFrequencyValue Pointer to uint8_t. On successful read, it can be:\n
 * 0 -       1 Hz\n
 * 1 -   4.096 KHz\n
 * 2 -   8.192 KHz\n
 * 3 -  32.768 KHz
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t frequencyCode;
 * status = I2C_RTCC_SquareWaveFrequencyGet(&frequencyCode);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_SquareWaveFrequencyGet( uint8_t *squareWaveFrequencyValue); //get values returned from datasheet   // PASSED

/**
 * Enables the output of the selected frequency on the MFP pin.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_SquareWaveEnable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_SquareWaveEnable(void); // sets SQWEN bit in CONTROL register                                           // PASSED

/**
 * Disables the output of the selected frequency on the MFP pin.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_SquareWaveDisable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_SquareWaveDisable(void); // clears SQWEN bit in CONTROL register                                        // PASSED 

/**
 * Shows the status of the output of the divided signal on the MFP pin. 
 * @param [out] *squareWaveEnabled Pointer to uint8_t. On successful read, it can be I2C_RTCC_SQWEN or 0 (zero).
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t squareWaveStatus;
 * status = I2C_RTCC_SquareWaveStatusGet(&squareWaveStatus);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_SquareWaveStatusGet( uint8_t *squareWaveEnabled); // gets value of SQWEN bit in CONTROL register   // PASSED
    
/**
 * Configures the MFP pin as GP output, and disables Square wave and Alarms functionality.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_GPOEnable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */    
ERR_STATUS_T I2C_RTCC_GPOEnable(void);                                            // PASSED

/**
 * Disables the output functionality of the MFP pin as GP output. Square wave or Alarms functionality are not enabled by default.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_GPODisable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */    
ERR_STATUS_T I2C_RTCC_GPODisable(void);                                             // PASSED
   
/**
 * Sets the value that will be output on MFP pin as High, when it is configured as GPO. Does not disable Alarms or Square wave functionality.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_SetOUTBitHigh();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_SetOUTBitHigh(void);                              // PASSED

/**
 * Sets the value that will be output on MFP pin as Low, when it is configured as GPO. Does not disable Alarms or Square wave functionality.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_SetOUTBitLow();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_SetOUTBitLow(void);                               // PASSED


/**
 * Enables Battery backup feature that switches the power source when Vcc voltage drops below Vtrip.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_BatteryBackupEnable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_BatteryBackupEnable(void);                          // PASSED

/**
 * Disables Battery backup feature.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_BatteryBackupDisable();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_BatteryBackupDisable(void);                         // PASSED

/**
 * Gets the status of the Battery backup feature.
 * @param [out] *bateryBackupEnabled Pointer to uint8_t. On successful read, it can be I2C_RTCC_VBATEN or 0 (zero). 
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t batteryStatus;
 * status = I2C_RTCC_BatteryBackupGet(&batteryStatus);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_BatteryBackupGet( uint8_t *bateryBackupEnabled);   // PASSED

/**
 * Shows if the current year is a Leap year.
 * @param [out] *isLeapYear Pointer to uint8_t. On successful read, it can be I2C_RTCC_LEAP_YEAR or 0 (zero). 
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t leapYear;
 * status = I2C_RTCC_LeapYearGet(&leapYear);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_LeapYearGet( uint8_t *isLeapYear);     // PASSED



/**
 * Writes a byte to the RTCC. It can be used to directly write to the registers.
 * @param [in] address uint8_t Hex variable. The address of the register to be written.
 * @param [in] data uint8_t variable. The data byte to be written.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * // Stops the oscillator and sets the Seconds value to "5"
 * status = I2C_RTCC_ByteWrite(I2C_RTCC_ADDR_RTCSEC, 0x05);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_ByteWrite( uint8_t address, uint8_t data );      // PASSED

/**
 * Reads a byte from the RTCC. It can be used to directly read the registers.
 * @param [in] address uint8_t Hex variable. The address of the register to be read.
 * @param [out] *data Pointer to uint8_t variable. The data from the device.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dataIn;
 * // get the status of the oscillator and Seconds value from address 0x00
 * status = I2C_RTCC_ByteRead(I2C_RTCC_ADDR_RTCSEC, &dataIn);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */ 
ERR_STATUS_T I2C_RTCC_ByteRead(  uint8_t address, uint8_t *data );      // PASSED


/**************************************************************************
 * EEPROM functions
 **************************************************************************/
/**
 * Writes data to the EEPROM part of the device.
 * @param [in] address uint8_t Hex variable. The address of the register to be written.
 * @param [in] length uint8_t variable. The number of bytes to be written. Maximum 8 data bytes can be written at once.
 * @param [in] *data Pointer to uint8_t array. The data string to be written.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dataIn[3] = { 0x80, 0x70, 0x60 };
 * // Write 3 bytes of data starting at address 0x00
 * status = I2C_RTCC_EE_DataWrite(0x00, 0x03, dataIn);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */  
ERR_STATUS_T I2C_RTCC_EE_DataWrite( uint8_t address, uint8_t length, uint8_t *data);    // PASSED

/**
 * Reads data from the EEPROM part of the device.
 * @param [in] address uint8_t Hex variable. The address of the register to be read.
 * @param [in] length uint8_t variable. The number of bytes to be read. Maximum 8 data bytes can be read at once.
 * @param [out] *data Pointer to uint8_t array. The data from device.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t dataOut[3];
 * // Read 3 bytes of data from EEPROM starting at address 0x00;
 * status = I2C_RTCC_EE_DataRead(0x00, 0x03, dataOut);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_DataRead( uint8_t address, uint8_t length, uint8_t *data);     // PASSED

/**
 * Sends the Unlock sequence to the device to unlock the Protected EEPROM.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_EE_UnlockSequence();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_UnlockSequence(void);

/**
 * Disables write protection for all EEPROM addresses.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_EE_ArrayProtectNone();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_ArrayProtectNone(void);

/**
 * Enables write-protection for the upper quarter EEPROM addresses.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_EE_ArrayProtectQuarter();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_ArrayProtectQuarter(void);

/**
 * Enables write-protection for the upper half EEPROM addresses.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_EE_ArrayProtectHalf();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_ArrayProtectHalf(void);

/**
 * Enables write-protection for all EEPROM addresses.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * status = I2C_RTCC_EE_ArrayProtectAll();
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_ArrayProtectAll(void);


/**
 * Gets the value of the STATUS register from the EEPROM.
 * @param [out] *statusRegister Pointer to uint8_t. The value of the STATUS register from device.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t statusRegisterValue;
 * status = I2C_RTCC_EE_StatusRegisterGet(&statusRegisterValue);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_StatusRegisterGet( uint8_t *statusRegister);    // PASSED

/**
 * Send the value to the STATUS register from the EEPROM. Only Block Protection bits can be written.
 * @param [in] statusRegister uint8_t variable. The value of the STATUS register to be written.
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t statusRegisterValue = 0x0C;
 * // set STATUS register to enable write protection for all EEPROM addresses.
 * status = I2C_RTCC_EE_StatusRegisterSet(statusRegisterValue);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_StatusRegisterSet( uint8_t statusRegister);     // PASSED

/**
 * Gets the code for write-protect feature.
 * @param [out] *blockProtectValue Pointer to uint8_t variable. On successful read, it can be:\n
 * 0 -  No address is write-protected\n
 * 1 -  Upper quarter array is protected\n
 * 2 -  Upper half array is protected\n
 * 3 -  Full array is protected
 * @retval ERR_I2C_MESSAGE_COMPLETE The communication was successful
 * @retval other I2C errors
 * 
 * Example Usage: 
 * @code
 * ERR_STATUS_T status;
 * uint8_t blockProtectCode;
 * status = I2C_RTCC_EE_BlockProtectGet(&blockProtectCode);
 * if (status != ERR_I2C_MESSAGE_COMPLETE ) return status;
 * // ...
 * @endcode
 */
ERR_STATUS_T I2C_RTCC_EE_BlockProtectGet( uint8_t *blockProtectValue);   // PASSED

/**************************************************************************
 * Other functions
 **************************************************************************/
 
 /**
 * Converts a binary value to BCD format.
 * @param [in] value uint8_t variable. Value to be converted to BCD.
 * @returns Value in BCD format
 * 
 * Example Usage: 
 * @code
 * uint8_t binaryNumber = 0x0A, bcdNumber;
 * bcdNumber = bin2bcd(binaryNumber);
 * // ...
 * @endcode
 */
uint8_t bin2bcd(uint8_t value);

 /**
 * Converts a BCD formated number to binary.
 * @param [in] value uint8_t variable. Value to be converted to binary.
 * @returns Value in binary format
 * 
 * Example Usage: 
 * @code
 * uint8_t bcdNumber = 0x23, binaryNumber;
 * binaryNumber = bin2bcd(bcdNumber);
 * // ...
 * @endcode
 */
uint8_t bcd2bin(uint8_t value);

#endif	/* MCP79XXX_H */
