/*==============================================================================
Copyright 2016 Microchip Technology Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "mcc.h"
#include "winc1500_api.h"

uint32_t GetOneMsCounter(void); 


#define WaitForDataByte()   while ((SPI1STATLbits.SPITBF == 1) || (SPI1STATLbits.SPIRBF == 0))

#if defined(USING_PICTAIL)
void m2mStub_PinSet_CE(t_m2mWifiPinAction action)
{
    if (action == M2M_WIFI_PIN_LOW)
    {
        IO_RG1_CE_SetLow();
    }
    else
    {
        IO_RG1_CE_SetHigh();
    }
}

void m2mStub_PinSet_RESET(t_m2mWifiPinAction action)
{
    if (action == M2M_WIFI_PIN_LOW)
    {
        IO_RG0_RESET_SetLow();
    }
    else
    {
        IO_RG0_RESET_SetHigh();
    }
}
#elif defined(USING_CLICK_BOARD)
void m2mStub_PinSet_CE(t_m2mWifiPinAction action)
{
    if (action == M2M_WIFI_PIN_LOW)
    {
        IO_RD0_CE_SetLow();
    }
    else
    {
        IO_RD0_CE_SetHigh();
    }
}

void m2mStub_PinSet_RESET(t_m2mWifiPinAction action)
{
    if (action == M2M_WIFI_PIN_LOW)
    {
        IO_RG14_RESET_SetLow();
    }
    else
    {
        IO_RG14_RESET_SetHigh();
    }
}


#endif


void m2mStub_PinSet_SPI_SS(t_m2mWifiPinAction action)
{
     if (action == M2M_WIFI_PIN_LOW)
    {
        IO_RG9_SS2_SetLow();
    }
    else
    {
        IO_RG9_SS2_SetHigh();
    }
}

uint32_t m2mStub_GetOneMsTimer(void)
{
    return GetOneMsCounter();   // function added to MCC generated timer1 code
}

void m2mStub_EintEnable(void)
{
    EX_INT3_InterruptEnable();  
}

void m2mStub_EintDisable(void)
{
    EX_INT3_InterruptDisable();
}

/*******************************************************************************
  Function:
    void m2mStub_SpiTxRx(void)

  Summary:
    Transmits and receives SPI bytes

  Description:
    Transmits and receives N bytes of SPI data.

  Precondition:
    None

  Parameters:
    p_txBuf - pointer to SPI tx data
    txLen   - number of bytes to Tx
    p_rxBuf - pointer to where SPI rx data will be stored
    rxLen   - number of SPI rx bytes caller wants copied to p_rxBuf

  Returns:
    None

  Remarks:
    Will clock out the larger of txLen or rxLen, and pad if necessary.
 *******************************************************************************/
void m2mStub_SpiTxRx(uint8_t *p_txBuf,
                    uint16_t txLen,
                    uint8_t *p_rxBuf,
                    uint16_t rxLen)
{
    uint16_t byteCount;
    uint16_t i;
    
    /* total number of byte to clock is whichever is larger, txLen or rxLen */
    byteCount = (txLen >= rxLen) ? txLen : rxLen;

    for (i = 0; i < byteCount; ++i)
    {
        /* if still have bytes to transmit from tx buffer */
        if (txLen > 0)
        {
            SPI1BUFL = *p_txBuf++;
            --txLen;
        }
        /* else done writing bytes out from tx buffer */
        else
        {
            SPI1BUFL = 0x00; /* clock out a "don't care" byte */
        }

        /* wait until tx/rx byte to completely clock out */
        WaitForDataByte();

        /* if still have bytes to read into rx buffer */
        if (rxLen > 0)
        {
            *p_rxBuf++ = SPI1BUFL;
            --rxLen;
        }
            /* else done reading bytes into rx buffer */
        else
        {
            SPI1BUFL; /* read and throw away byte */
        }
    } /* end for loop */
}
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
//con == SPIxCONL, brg == SPIxBRGL, operation == Master/Slave
typedef struct { uint16_t con1; uint16_t brg; uint8_t operation;} spi1_configuration_t;
static const spi1_configuration_t spi1_configuration[] = {   
    { 0x0120, 0x003F, 0 },
    { 0x0120, 0x0000, 0 }
};

typedef enum { 
    SPI1_DEFAULT,
    WINC_CONFIG
} spi1_modes;

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool spi1_open(spi1_modes spiUniqueConfiguration)
{
    if(!SPI1CON1Lbits.SPIEN)
    {
        SPI1CON1L = spi1_configuration[spiUniqueConfiguration].con1;
        SPI1BRGL = spi1_configuration[spiUniqueConfiguration].brg;
        
        TRISCbits.TRISC2 = spi1_configuration[spiUniqueConfiguration].operation;
        SPI1CON1Lbits.SPIEN = 1;
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void SpiInit(void)
{
    spi1_open(WINC_CONFIG);
}

#if defined(M2M_ENABLE_SPI_FLASH)
void m2m_wifi_console_write_data(uint16_t length, uint8_t *p_buf)
{
    uint16_t i;
    
    for (i = 0; i < length; ++i)
    {
        UART2_Write(p_buf[i]);
    }
}

uint8_t m2m_wifi_console_read_data(void)
{
    return UART2_Read();
}

bool m2m_wifi_console_is_read_data(void)
{
    return (U2STAbits.URXDA == 1);
}
#endif // M2M_ENABLE_SPI_FLASH