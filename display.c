
#include "display.h"

char text[] = "USD=4,02";
char text1[] = "EUR=4,34";
char text2[] = "GBP=4,99";
char text3[] = "CZK=0,18";
char title[] = "currency  rates";
char info[] = "press button to swipe";


void DrawGreenArrow (int16_t y){
    TFTfillTriangle(110, y, 120 , y, 115, y-10, ST7735_GREEN);
}
    
void DrawRedArrow (int16_t y){
    TFTfillTriangle(110, y, 120 , y, 115, y+10, ST7735_RED);
}
//void TFTdrawText(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);
void DrawPage(uint16_t text_color){
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
    
    
    


