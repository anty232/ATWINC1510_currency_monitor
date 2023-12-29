
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
  
    
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TFTBlackTabInitialize();
    TFTFontNum(TFTFont_Default);
   
    
	TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    TFTfillScreen(ST7735_BLACK);
    
   
    
    while (1)
    {   
        DrawPage(ST7735_CYAN, text, text1, text2, text3);
        
    }

    return 1;
}
/**
 End of File
*/

