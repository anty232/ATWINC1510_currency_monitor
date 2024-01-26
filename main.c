
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "ST7735_TFT_BLACK.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include "API_Decoder.h"


    uint8_t OFFSET_COL = 2;  // 2, These offsets can be adjusted for any issues->
	uint8_t OFFSET_ROW = 1 ; // 3, with manufacture tolerance/defects
	uint8_t TFT_PIXEL_WIDTH = 128;// Screen width in pixels
	uint8_t TFT_PIXEL_HEIGHT = 160; // Screen height in pixels

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TFTBlackTabInitialize();
    TFTFontNum(TFTFont_Default);
	TFTInitScreenSize(OFFSET_COL, OFFSET_ROW , TFT_PIXEL_WIDTH  , TFT_PIXEL_HEIGHT);
    TFTfillScreen(ST7735_BLACK);
    UbdateValue();
    while (1)
    {   
     
    }

    return 1;
}
/**
 End of File
*/

