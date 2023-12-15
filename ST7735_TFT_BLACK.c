
#include "ST7735_TFT_BLACK.h"
#include "mcc_generated_files/spi1.h"

uint8_t _TFTCurrentFontWidth = 5;
bool _TFTwrap = true;

uint8_t _TFTType; 
uint8_t _TFTrotation = 0;

uint8_t _TFTcolstart; 
uint8_t _TFTrowstart;
uint8_t  _TFTxstart;  //  never change after first init
uint8_t  _TFTystart ; //  never change after first init

uint8_t _widthTFT;
uint8_t _heightTFT;
uint8_t _widthStartTFT; //  never change after first init
uint8_t _heightStartTFT; // never change after first init

void __delay_ms(uint16_t ms){
    
    for (int i = 0; i < ms ; i++){
        for(int j = 0; j < 1000 ; j++){    
        }
    }
}


void TFTwriteData(uint8_t data) {
    DC_RB5_SetHigh();
    CS_RB6_SetLow();
    SPI1_Exchange8bit( data );
    CS_RB6_SetHigh();
}

void TFTwriteCommand(uint8_t cmd) {
    DC_RB5_SetLow();
    CS_RB6_SetLow();
    SPI1_Exchange8bit( cmd );
    CS_RB6_SetHigh();
}

void TFTspiWriteBuffer(uint8_t* spidata, size_t len) {
	DC_RB5_SetHigh();
    CS_RB6_SetLow();
    SPI1_Exchange8bitBuffer(spidata, len, 0);
    CS_RB6_SetHigh();
}

void TFTspiWriteByte(uint8_t spidata) {
    DC_RB5_SetHigh();
    CS_RB6_SetLow();
    SPI1_Exchange8bitBuffer(&spidata, sizeof (spidata) , 0);
    CS_RB6_SetHigh();
}

void TFTResetPIN() {
    RST_RB15_SetDigitalOutput();
    RST_RB15_SetHigh();
    __delay_ms(10);
    RST_RB15_SetLow();
    __delay_ms(10);
    RST_RB15_SetHigh();
    __delay_ms(10);
}

void TFTBcmd() {
    TFTwriteCommand(ST7735_SWRESET);
    __delay_ms(50);
    TFTwriteCommand(ST7735_SLPOUT);
    __delay_ms(500);
    TFTwriteCommand(ST7735_COLMOD);
    TFTwriteData(0x05);
    __delay_ms(10);
    TFTwriteCommand(ST7735_FRMCTR1);
    TFTwriteData(0x00);
    TFTwriteData(0x06);
    TFTwriteData(0x03);
    __delay_ms(10);
    TFTwriteCommand(ST7735_MADCTL);
    TFTwriteData(0x08);
    TFTwriteCommand(ST7735_DISSET5);
    TFTwriteData(0x15);
    TFTwriteData(0x02);
    TFTwriteCommand(ST7735_INVCTR);
    TFTwriteData(0x00);
    TFTwriteCommand(ST7735_PWCTR1);
    TFTwriteData(0x02);
    TFTwriteData(0x70);
    __delay_ms(10);
    TFTwriteCommand(ST7735_PWCTR2);
    TFTwriteData(0x05);
    TFTwriteCommand(ST7735_PWCTR3);
    TFTwriteData(0x01);
    TFTwriteData(0x02);
    TFTwriteCommand(ST7735_VMCTR1);
    TFTwriteData(0x3C);
    TFTwriteData(0x38);
    __delay_ms(10);
    TFTwriteCommand(ST7735_PWCTR6);
    TFTwriteData(0x11);
    TFTwriteData(0x15);
    TFTwriteCommand(ST7735_GMCTRP1);
    uint8_t seq6[] = {0x09, 0x16, 0x09, 0x20, 0x21, 0x1B, 0x13, 0x19, 0x17, 0x15, 0x1E, 0x2B, 0x04, 0x05, 0x02, 0x0E};
    TFTspiWriteBuffer(seq6, sizeof(seq6));
    TFTwriteCommand(ST7735_GMCTRN1);
    uint8_t seq7[]= {0x0B, 0x14, 0x08, 0x1E, 0x22, 0x1D, 0x18, 0x1E, 0x1B, 0x1A, 0x24, 0x2B, 0x06, 0x06, 0x02, 0x0F}; 
    TFTspiWriteBuffer(seq7, sizeof(seq7));
    __delay_ms(10);
    TFTwriteCommand(ST7735_CASET);
    TFTwriteData(0x00);
    TFTwriteData(0x02);
    TFTwriteData(0x08);
    TFTwriteData(0x81);
    TFTwriteCommand(ST7735_RASET);
    TFTwriteData(0x00);
    TFTwriteData(0x01);
    TFTwriteData(0x08);
    TFTwriteData(0xA0);
    TFTwriteCommand(ST7735_NORON);
    __delay_ms(10);
    TFTwriteCommand(ST7735_DISPON);
    __delay_ms(500);
}

void TFTRcmd1() {
    
    uint8_t seq1[] = {0x01, 0x2C, 0x2D};
	uint8_t seq2[] = {0xA2, 0x02, 0x84};
   
    TFTwriteCommand(ST7735_SWRESET);
    __delay_ms(150);
    TFTwriteCommand(ST7735_SLPOUT);
    __delay_ms(500);
    TFTwriteCommand(ST7735_FRMCTR1);
    
    TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTwriteCommand(ST7735_FRMCTR2);
	TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTwriteCommand(ST7735_FRMCTR3);
    TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTwriteCommand(ST7735_INVCTR);
    TFTwriteData(0x07);
    TFTwriteCommand(ST7735_PWCTR1);
    TFTspiWriteBuffer(seq2, sizeof(seq2));
    TFTwriteCommand(ST7735_PWCTR2);
    TFTwriteData(0xC5);
    TFTwriteCommand(ST7735_PWCTR3);
    TFTwriteData(0x0A);
    TFTwriteData(0x00);
    TFTwriteCommand(ST7735_PWCTR4);
    TFTwriteData(0x8A);
    TFTwriteData(0x2A);
    TFTwriteCommand(ST7735_PWCTR5);
    TFTwriteData(0x8A);
    TFTwriteData(0xEE);
    TFTwriteCommand(ST7735_VMCTR1);
    TFTwriteData(0x0E);
    TFTwriteCommand(ST7735_INVOFF);
    TFTwriteCommand(ST7735_MADCTL);
    TFTwriteData(0xC8);
    TFTwriteCommand(ST7735_COLMOD);
    TFTwriteData(0x05);
}

void TFTRcmd2red() {
    uint8_t seq1[] = {0x00, 0x00, 0x00, 0x7F};
	uint8_t seq2[] = {0x00, 0x00, 0x00, 0x9F};
    TFTwriteCommand(ST7735_CASET);
    TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTwriteCommand(ST7735_RASET);
    TFTspiWriteBuffer(seq2, sizeof(seq2));
}

void TFTRcmd3() {
    uint8_t seq1[] = {0x02, 0x1C, 0x07, 0x12, 0x37, 0x32, 0x29, 0x2D, 0x29, 0x25, 0x2B, 0x39, 0x00, 0x01, 0x03, 0x10};
    uint8_t seq2[] = {0x03, 0x1D, 0x07, 0x06, 0x2E, 0x2C, 0x29, 0x2D, 0x2E, 0x2E, 0x37, 0x3F, 0x00, 0x00, 0x02, 0x10};
    TFTwriteCommand(ST7735_GMCTRP1);
    TFTspiWriteBuffer(seq1, sizeof(seq1));
    TFTwriteCommand(ST7735_GMCTRN1);
    TFTspiWriteBuffer(seq2, sizeof(seq2));
    TFTwriteCommand(ST7735_NORON);
    __delay_ms(10);
    TFTwriteCommand(ST7735_DISPON);
    __delay_ms(100);
}


void TFTBlackTabInitialize() {
    TFTResetPIN();
    CS_RB6_SetHigh();
    DC_RB5_SetLow();
    CS_RB6_SetDigitalOutput();
    DC_RB5_SetDigitalOutput();
    TFTRcmd1();
    TFTRcmd2red();
    TFTRcmd3();
    TFTwriteCommand(ST7735_MADCTL);
    TFTwriteData(0xC0);
    //_TFTType = TFT_ST7735S_Black;
}

void TFTsetAddrWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
    TFTwriteCommand(ST7735_CASET);
    TFTwriteData(0);
    TFTwriteData((uint8_t)x0 + _TFTxstart);
    TFTwriteData(0);
    TFTwriteData((uint8_t)x1 + _TFTxstart);
    TFTwriteCommand(ST7735_RASET);
    TFTwriteData(0);
    TFTwriteData((uint8_t)y0 + _TFTystart);
    TFTwriteData(0);
    TFTwriteData((uint8_t)y1 + _TFTystart);
    TFTwriteCommand(ST7735_RAMWR); // Write to RAM
}

void TFTdrawPixel(int16_t x, int16_t y, uint16_t color) {
    if ((x >= _widthTFT) || (y >= _heightTFT))
        return;
    TFTsetAddrWindow(x, y, x + 1, y + 1);
    TFTwriteData(color >> 8);
    TFTwriteData(color & 0xFF);
}


void TFTdrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
    uint8_t hi, lo;
    if ((x >= _widthTFT) || (y >= _heightTFT))
        return;
    if ((y + h - 1) >= _heightTFT)
        h = _heightTFT - y;
    hi = color >> 8;
    lo = color & 0xFF;
    TFTsetAddrWindow(x, y, x, y + h - 1);
    DC_RB5_SetHigh();
    CS_RB6_SetLow();
    while (h--) {
        TFTspiWriteByte(hi);
        TFTspiWriteByte(lo);
    }
    CS_RB6_SetHigh();
}

void TFTfillRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    
        uint8_t hi, lo;
    if ((x >= _widthTFT) || (y >= _heightTFT))
        return;
    if ((x + w - 1) >= _widthTFT)
        w = _widthTFT - x;
    if ((y + h - 1) >= _heightTFT)
        h = _heightTFT - y;
    TFTsetAddrWindow(x, y, x + w - 1, y + h - 1);
    hi = color >> 8;
    lo = color & 0xFF;
    DC_RB5_SetHigh();
    CS_RB6_SetLow();
    for (y = h; y > 0; y--) {
        for (x = w; x > 0; x--) {
            TFTspiWriteByte(hi);
            TFTspiWriteByte(lo);
        }
    }
    CS_RB6_SetHigh();
    
}

void TFTfillScreen(uint16_t color) {
    TFTfillRectangle(0, 0, _widthTFT, _heightTFT, color);
}


void TFTInitScreenSize(uint8_t colOffset, uint8_t rowOffset, uint8_t width_TFT, uint8_t height_TFT)
{
	_TFTcolstart = colOffset; 
	_TFTrowstart= rowOffset;
	_TFTxstart = colOffset;  // Holds init value will never change after this point
	_TFTystart = rowOffset; // Holds init value will never change after this point
	
	_widthTFT = width_TFT;
	_heightTFT = height_TFT;
	_widthStartTFT = width_TFT; // Holds init value will never change after this point
	_heightStartTFT = height_TFT; // Holds init value will never change after this point
}

