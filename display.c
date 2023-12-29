
#include "display.h"

char text[] = "USD=4,02";
char title[] = "currency rates";
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
    TFTdrawText(0, 60, text, text_color, ST7735_BLACK, 2);
    TFTdrawText(0, 80, text, text_color, ST7735_BLACK, 2);
    TFTdrawText(0, 100, text, text_color, ST7735_BLACK, 2);
    DrawGreenArrow (50);
    DrawRedArrow (60);
    DrawGreenArrow (90);
    DrawRedArrow (100);
    TFTdrawText(0, 140, info, ST7735_GREEN, ST7735_BLACK, 1);
}
    
    
    


