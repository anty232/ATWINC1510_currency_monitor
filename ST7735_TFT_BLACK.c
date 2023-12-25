
#include "ST7735_TFT_BLACK.h"
#include "ST7735_TFT_Font.h"
#include "mcc_generated_files/spi1.h"


uint8_t _TFTFontNumber = TFTFont_Default ;
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

void TFTdrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
    uint8_t hi, lo;
    if ((x >= _widthTFT) || (y >= _heightTFT))
        return;
    if ((x + w - 1) >= _widthTFT)
        w = _widthTFT - x;
    hi = color >> 8;
    lo = color & 0xFF;
    TFTsetAddrWindow(x, y, x + w - 1, y);
    DC_RB5_SetHigh();
    CS_RB6_SetLow();
    while (w--) {
        TFTspiWriteByte(hi);
        TFTspiWriteByte(lo);
    }
    CS_RB6_SetHigh();
}


void TFTdrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    int16_t f, ddF_x, ddF_y,x ,y;
    f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
    TFTdrawPixel(x0, y0 + r, color);
    TFTdrawPixel(x0, y0 - r, color);
    TFTdrawPixel(x0 + r, y0, color);
    TFTdrawPixel(x0 - r, y0, color);
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        TFTdrawPixel(x0 + x, y0 + y, color);
        TFTdrawPixel(x0 - x, y0 + y, color);
        TFTdrawPixel(x0 + x, y0 - y, color);
        TFTdrawPixel(x0 - x, y0 - y, color);
        TFTdrawPixel(x0 + y, y0 + x, color);
        TFTdrawPixel(x0 - y, y0 + x, color);
        TFTdrawPixel(x0 + y, y0 - x, color);
        TFTdrawPixel(x0 - y, y0 - x, color);
    }
}

void TFTdrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) {
    int16_t f, ddF_x, ddF_y, x, y ;
    f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        if (cornername & 0x4) {
            TFTdrawPixel(x0 + x, y0 + y, color);
            TFTdrawPixel(x0 + y, y0 + x, color);
        }
        if (cornername & 0x2) {
            TFTdrawPixel(x0 + x, y0 - y, color);
            TFTdrawPixel(x0 + y, y0 - x, color);
        }
        if (cornername & 0x8) {
            TFTdrawPixel(x0 - y, y0 + x, color);
            TFTdrawPixel(x0 - x, y0 + y, color);
        }
        if (cornername & 0x1) {
            TFTdrawPixel(x0 - y, y0 - x, color);
            TFTdrawPixel(x0 - x, y0 - y, color);
        }
    }
}

void TFTfillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
    int16_t f, ddF_x, ddF_y,x ,y;
    f = 1 - r, ddF_x = 1, ddF_y = -2 * r, x = 0, y = r;
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        if (cornername & 0x1) {
            TFTdrawFastVLine(x0 + x, y0 - y, 2 * y + 1 + delta, color);
            TFTdrawFastVLine(x0 + y, y0 - x, 2 * x + 1 + delta, color);
        }
        if (cornername & 0x2) {
            TFTdrawFastVLine(x0 - x, y0 - y, 2 * y + 1 + delta, color);
            TFTdrawFastVLine(x0 - y, y0 - x, 2 * x + 1 + delta, color);
        }
    }
}

void TFTfillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    TFTdrawFastVLine(x0, y0 - r, 2 * r + 1, color);
    TFTfillCircleHelper(x0, y0, r, 3, 0, color);
}

// Desc: draws rectangle at (x,y) where h is height and w is width of the rectangle.

void TFTdrawRectWH(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    TFTdrawFastHLine(x, y, w, color);
    TFTdrawFastHLine(x, y + h - 1, w, color);
    TFTdrawFastVLine(x, y, h, color);
    TFTdrawFastVLine(x + w - 1, y, h, color);
}


void TFTdrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    int16_t steep, dx, dy, err, ystep;
    steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        _swap_TFT(x0, y0);
        _swap_TFT(x1, y1);
    }
    if (x0 > x1) {
        _swap_TFT(x0, x1);
        _swap_TFT(y0, y1);
    }
    dx = x1 - x0;
    dy = abs(y1 - y0);

    err = dx / 2;
    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0 <= x1; x0++) {
        if (steep) {
            TFTdrawPixel(y0, x0, color);
        } else {
            TFTdrawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

void TFTfillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    int16_t i;
    for (i = x; i < x + w; i++) {
        TFTdrawFastVLine((uint8_t)i, y, h, color);
    }
}

// Desc: draws a rectangle with rounded edges. h: height, w:width, r: radius of the rounded edges.

void TFTdrawRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color) {
    TFTdrawFastHLine(x + r, y, w - 2 * r, color);
    TFTdrawFastHLine(x + r, y + h - 1, w - 2 * r, color);
    TFTdrawFastVLine(x, y + r, h - 2 * r, color);
    TFTdrawFastVLine(x + w - 1, y + r, h - 2 * r, color);
    TFTdrawCircleHelper(x + r, y + r, r, 1, color);
    TFTdrawCircleHelper(x + w - r - 1, y + r, r, 2, color);
    TFTdrawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
    TFTdrawCircleHelper(x + r, y + h - r - 1, r, 8, color);
}

// Desc: draws a filled rectangle with rounded edges. h: height, w:width, r: radius of the rounded edges.

void TFTfillRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color) {
    TFTfillRect(x + r, y, w - 2 * r, h, color);
    TFTfillCircleHelper(x + w - r - 1, y + r, r, 1, h - 2 * r - 1, color);
    TFTfillCircleHelper(x + r, y + r, r, 2, h - 2 * r - 1, color);
}

void TFTdrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    TFTdrawLine(x0, y0, x1, y1, color);
    TFTdrawLine(x1, y1, x2, y2, color);
    TFTdrawLine(x2, y2, x0, y0, color);
}

// Desc: draws a filled triangle of coordinates (x0,y0), (x1,y1) and (x2,y2).

void TFTfillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    int16_t a, b, y, last, dx01, dy01, dx02, dy02, dx12, dy12, sa, sb;
    if (y0 > y1) {
        _swap_TFT(y0, y1);
        _swap_TFT(x0, x1);
    }
    if (y1 > y2) {
        _swap_TFT(y2, y1);
        _swap_TFT(x2, x1);
    }
    if (y0 > y1) {
        _swap_TFT(y0, y1);
        _swap_TFT(x0, x1);
    }
    if (y0 == y2) {
        a = b = x0;
        if (x1 < a) a = x1;
        else if (x1 > b) b = x1;
        if (x2 < a) a = x2;
        else if (x2 > b) b = x2;
        TFTdrawFastHLine(a, y0, b - a + 1, color);
        return;
    }
    dx01 = x1 - x0;
    dy01 = y1 - y0;
    dx02 = x2 - x0;
    dy02 = y2 - y0;
    dx12 = x2 - x1;
    dy12 = y2 - y1;
    sa = 0;
    sb = 0;
    if (y1 == y2) last = y1;
    else last = y1 - 1;
    for (y = y0; y <= last; y++) {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;
        if (a > b) _swap_TFT(a, b);
        TFTdrawFastHLine(a, y, b - a + 1, color);
    }

    sa = dx12 * (y - y1);
    sb = dx02 * (y - y0);
    for (; y <= y2; y++) {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;
        if (a > b) _swap_TFT(a, b);
        TFTdrawFastHLine(a, y, b - a + 1, color);
    }
}

void TFTdrawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg, uint8_t size) {
    const uint8_t ASCIIOffset = 0x20;
    uint8_t i, j;
    
    if ((x >= _widthTFT) || (y >= _heightTFT))
        return;
    if (size < 1) size = 1;
    if ((c < ' ') || (c > '~'))
        c = '?';
    for (i = 0; i < _TFTCurrentFontWidth; i++) {
        uint8_t line;
        switch (_TFTFontNumber) {
            case 1:
#ifdef TFT_Font_Default
                line = pFontDefaultptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];            
#endif
                break;
            case 2:
#ifdef TFT_Font_Thick
                line = pFontThickptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];
#endif
                break;
            case 3:
#ifdef TFT_Font_SevenSeg
                line = pFontSevenptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];
#endif
                break;
            case 4:
#ifdef TFT_Font_Wide
                line = pFontWideptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];
#endif
                break;
            case 5:
#ifdef TFT_Font_Tiny
                line = pFontTinyptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];
#endif
                break;
            case 6:
#ifdef TFT_Font_HomeSpun
                line = pFontHomeptr[(c - ASCIIOffset) * _TFTCurrentFontWidth + i];
#endif
                break;
        }
        for (j = 0; j < 7; j++, line >>= 1) {
            if (line & 0x01) {
                if (size == 1) TFTdrawPixel(x + i, y + j, color);
                else TFTfillRect(x + (i * size), y + (j * size), size, size, color);
            } else if (bg != color) {
                if (size == 1) TFTdrawPixel(x + i, y + j, bg);
                else TFTfillRect(x + i*size, y + j*size, size, size, bg);
            }
        }
    }
}


void TFTsetTextWrap(bool w) {
    _TFTwrap = w;
}

// Desc: Writes text (*text) on the TFT at coordinates (x, y). size: text size.

void TFTdrawText(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size) {
    uint8_t cursor_x, cursor_y;
    uint16_t textsize, i;
    cursor_x = x, cursor_y = y;
    textsize = strlen(_text);
    for (i = 0; i < textsize; i++) {
        if (_TFTwrap && ((cursor_x + size * _TFTCurrentFontWidth) > _widthTFT)) {
            cursor_x = 0;
            cursor_y = cursor_y + size * 7 + 3;
            if (cursor_y > _heightTFT) cursor_y = _heightTFT;
            if (_text[i] == 0x20) goto _skip;
        }
        TFTdrawChar(cursor_x, cursor_y, _text[i], color, bg, size);
        cursor_x = cursor_x + size * (_TFTCurrentFontWidth + 1);
        if (cursor_x > _widthTFT) cursor_x = _widthTFT;
_skip:
        ;
    }
}

//  Desc :  Set the font number
// Param1: fontnumber 1-6 enum ST7735_FontType_e
// 1=default 2=thick 3=seven segment 4=wide 5=tiny 6=homespun
// Fonts must be enabled at top of header file.
void TFTFontNum(ST7735_FontType_e FontNumber) {

   _TFTFontNumber = FontNumber;

    switch (_TFTFontNumber ) {
        case TFTFont_Default: _TFTCurrentFontWidth = TFTFont_width_5;
            break; // Norm default 5 by 8
        case TFTFont_Thick: _TFTCurrentFontWidth = TFTFont_width_7;
            break; //Thick 7 by 8 (NO LOWERCASE LETTERS)
        case TFTFont_Seven_Seg: _TFTCurrentFontWidth = TFTFont_width_4;
            break; //Seven segment 4 by 8
        case TFTFont_Wide: _TFTCurrentFontWidth = TFTFont_width_8;
            break; // Wide  8 by 8 (NO LOWERCASE LETTERS)
        case TFTFont_Tiny: _TFTCurrentFontWidth = TFTFont_width_3;
            break; //Tiny 3 by 8
        case TFTFont_Homespun: _TFTCurrentFontWidth = TFTFont_width_7;
            break; //homespun 7 by 8 
    }
}
