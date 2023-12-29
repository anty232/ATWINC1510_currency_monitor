
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"

    uint8_t data1 = 0x21;
    uint8_t data2 = 0x37;
    uint8_t recived;
    uint8_t recived2;
   // SPI1_STATUS status;
    uint8_t OFFSET_COL = 2;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 1 ; // 3, with manufacture tolerance/defects
	uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
	uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels
    char text[] = "USD=4,02";
    char title[] = "currency rates";
    char info[] = "press button to swipe";
  
    
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TFTBlackTabInitialize();
    TFTFontNum(TFTFont_Default);
   
    
	TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    TFTfillScreen(ST7735_BLACK);
    
    
    void DrawGreenArrow (int16_t y){
        TFTfillTriangle(110, y, 120 , y, 115, y-10, ST7735_GREEN);
    }
    
    void DrawRedArrow (int16_t y){
        TFTfillTriangle(110, y, 120 , y, 115, y+10, ST7735_RED);
    }
    //void TFTdrawText(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);
    void DrawPage(uint16_t text_color){
        TFTdrawText(0, 0, title, ST7735_GREEN, ST7735_BLACK, 1);
        TFTdrawText(0, 40, text, text_color, ST7735_BLACK, 2);
        TFTdrawText(0, 60, text, text_color, ST7735_BLACK, 2);
        TFTdrawText(0, 80, text, text_color, ST7735_BLACK, 2);
        TFTdrawText(0, 100, text, text_color, ST7735_BLACK, 2);
        DrawGreenArrow (50);
        DrawRedArrow (60);
        DrawGreenArrow (90);
        DrawRedArrow (100);
        TFTdrawText(0, 140, info, ST7735_GREEN, ST7735_BLACK, 1);
    }
    
    
    
    
    while (1)
    {   
        DrawPage(ST7735_CYAN);
        //TFTfillRect(110, 40, 10, 9, ST7735_GREEN );
        //TFTfillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
        
    }

    return 1;
}
/**
 End of File
*/

