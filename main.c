
#include "mcc_generated_files/system.h"
#include "display.h"
#include "API_Decoder.h"


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    StartScreen();
    UbdateValue();
    
    while (1)
    {   
     
    }

    return 1;
}
/**
 End of File
*/

