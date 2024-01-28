
#include "mcc_generated_files/system.h"
#include "display.h"
#include "API_Decoder.h"


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    StartScreen();
    UbdateValue("THB", "USD", "AUD", "HKD"); 
    DrawPage(ST7735_CYAN, text, text1, text2, text3);
    
    while (1)
    {   
     
    }

    return 1;
}
/**
 End of File
*/

