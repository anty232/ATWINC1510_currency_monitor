
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include "API_Decoder.h"


    uint8_t OFFSET_COL = 2;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 1 ; // 3, with manufacture tolerance/defects
	uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
	uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels
    int i =9;
    char resoult[9];
    char text[9];
    char text1[] = "EUR=4,34";
    char text2[] = "GBP=4,99";
    char text3[] = "CZK=0,18";
    char text4[] = "INR=0,04";
    char text5[] = "BGN=2,24";
    char text6[] = "MXN=0,23";
    char text7[] = "NPR=0,03";
    //snprintf(resoult, sizeof(resoult), "%s=%s", "USD", CurrencyValue("USD"));
    sizeof(text);
    uint8_t State =0;

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
                State = State %2;
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
        uint8_t State2 =0;
        State2 = State;
        GetButton();
        if(State2!=State){
            switch(State){
                case 0:
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 1:
                    DrawPage(ST7735_CYAN, text4, text5, text6, text7);
                    break;
                default:
                    break;
            }
        }
        else{
            
        }
    }
    
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TFTBlackTabInitialize();
    TFTFontNum(TFTFont_Default);
    TMR1_Start();
   
	TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    TFTfillScreen(ST7735_BLACK);
    DrawPage(ST7735_CYAN, text, text1, text2, text3);
    
    while (1)
    {   
        StateMachine();
        
    }

    return 1;
}
/**
 End of File
*/

