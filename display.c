
#include "display.h"


char title[] = "currency  rates";
char info[] = "press button to swipe";

uint8_t OFFSET_COL = 2;  // 2, These offsets can be adjusted for any issues->
uint8_t OFFSET_ROW = 1 ; // 3, with manufacture tolerance/defects
uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels

void DrawGreenArrow (int16_t y){
    TFTfillTriangle(110, y, 120 , y, 115, y-10, ST7735_GREEN);
}
    
void DrawRedArrow (int16_t y){
    TFTfillTriangle(110, y, 120 , y, 115, y+10, ST7735_RED);
}
//void TFTdrawText(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);
void DrawPage(uint16_t text_color, char *text, char *text1, char *text2, char *text3){
    TFTdrawText(0, 0, title, ST7735_GREEN, ST7735_BLACK, 2);
    TFTdrawText(0, 40, text, text_color, ST7735_BLACK, 2);
    TFTdrawText(0, 65, text1, text_color, ST7735_BLACK, 2);
    TFTdrawText(0, 90, text2, text_color, ST7735_BLACK, 2);
    TFTdrawText(0, 115, text3, text_color, ST7735_BLACK, 2);
    DrawGreenArrow (50);
    DrawRedArrow (65);
    DrawGreenArrow (100);
    DrawRedArrow (115);
    TFTdrawText(0, 140, info, ST7735_GREEN, ST7735_BLACK, 1);
}
    
void StartScreen(void){
    
    TFTBlackTabInitialize();
    TFTFontNum(TFTFont_Default);
	TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    TFTfillScreen(ST7735_BLACK);
   
}
    


