
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"
#include "display.h"

   
    uint8_t OFFSET_COL = 2;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 1 ; // 3, with manufacture tolerance/defects
	uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
	uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels
   
    char text[] = "USD=4,02";
    char text1[] = "EUR=4,34";
    char text2[] = "GBP=4,99";
    char text3[] = "CZK=0,18";
    
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
        uint8_t State2 =0;
        State2 = State;
        GetButton();
        if(State2!=State){
            switch(State){
                case 0:
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 1:
                    DrawPage(ST7735_CYAN, text1, text2, text3, text);
                    break;
                case 2:          
                    DrawPage(ST7735_CYAN, text2, text3, text, text1);
                    break;
                case 3:
                    DrawPage(ST7735_CYAN, text3, text, text1, text2);
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

