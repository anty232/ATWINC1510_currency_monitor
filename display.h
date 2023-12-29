
#ifndef DISPLAY
#define	DISPLAY

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"


void DrawGreenArrow (int16_t y);
void DrawRedArrow (int16_t y);
void DrawPage(uint16_t text_color, char *text, char *text1, char *text2, char *text3);




#endif	/* XC_HEADER_TEMPLATE_H */

