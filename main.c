
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"

    uint8_t data1 = 0x21;
    uint8_t data2 = 0x37;
    uint8_t recived;
    uint8_t recived2;
   // SPI1_STATUS status;
    uint8_t OFFSET_COL = 0;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 0 ; // 3, with manufacture tolerance/defects
	uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
	uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels



uint8_t State=0;
uint16_t portValue;

void GetButton(void){
    if(SW_0_GetValue()==0){
        __delay_ms(10);
        if(SW_0_GetValue()==0){
            State--;
            State= State %4;
            while(SW_0_GetValue()==0){
                Nop();
            }
        }
        else{
            State = State;
        }
    } 
    else if(SW_1_GetValue()==0){
            __delay_ms(10);
        if(SW_1_GetValue()==0){
            State++;
            State = State %4;
            while(SW_1_GetValue()==0){
                Nop();
            }
        }
        else{
                State = State;
        }
    } 
    else {
        State = State;
    }

}

void StateMachine(void){
    GetButton();
    GREEN_LED_SetHigh();
    YELLOW_LED_SetHigh();
    RED_LED_SetHigh();
    BLUE_LED_SetHigh();
    switch(State){
        case 0:
            RED_LED_SetLow();
            break;
        case 1:
            YELLOW_LED_SetLow();
            break;
        case 2:          
            GREEN_LED_SetLow();
            break;
        case 3:
            BLUE_LED_SetLow();
            break;
        default:
            break;
    }
}



int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //TFTBlackTabInitialize();
   
    
	//TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    
    while (1)
    {   
       // TFTfillScreen(ST7735_MAGENTA);
        //TFTdrawPixel(10, 10, ST7735_BLACK);
        //TFTdrawFastVLine(50, 50, 50, ST7735_BLACK);
        portValue=SW_0_GetValue();
        StateMachine();
        /*
        if(SW_1_GetValue()==0){
            GREEN_LED_Toggle();
            __delay_ms(50);
        }
         */
        
    }

    return 1;
}
/**
 End of File
*/

