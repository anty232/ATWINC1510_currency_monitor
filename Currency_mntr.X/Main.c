/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/


#include "mcc_generated_files/system.h"
#include "xc.h"
#include "spi1.h"
#include "ST7735.h"
#include "pin_manager.h"
#include "delay.h"
#include <stdio.h>


uint8_t k = 0;
char *txt = "1.8 Inch ST7735 TFT  display test example";
void testlines(uint16_t color) {
  uint8_t x, y;
  fillScreen(ST7735_BLACK);
  for (x=0; x < _width; x+=6) {
    drawLine(0, 0, x, _height-1, color);
  }
  for (y=0; y < _height; y+=6) {
    drawLine(0, 0, _width-1, y, color);
  }
 
  fillScreen(ST7735_BLACK);
  for (x=0; x < _width; x+=6) {
    drawLine(_width-1, 0, x, _height-1, color);
  }
  for (y=0; y < _height; y+=6) {
    drawLine(_width-1, 0, 0, y, color);
  }
 
  fillScreen(ST7735_BLACK);
  for (x=0; x < _width; x+=6) {
    drawLine(0, _height-1, x, 0, color);
  }
  for (y=0; y < _height; y+=6) {
    drawLine(0, _height-1, _width-1, y, color);
  }
 
  fillScreen(ST7735_BLACK);
  for (x=0; x < _width; x+=6) {
    drawLine(_width-1, _height-1, x, 0, color);
  }
  for (y=0; y < _height; y+=6) {
    drawLine(_width-1, _height-1, 0, y, color);
  }
}
void testfastlines(uint16_t color1, uint16_t color2) {
  int16_t x, y;
  fillScreen(ST7735_BLACK);
  for (y = 0; y < _height; y += 5) {
    drawFastHLine(0, y, _width, color1);
  }
  for (x = 0; x < _width; x += 5) {
    drawFastVLine(x, 0, _height, color2);
  }
}
void testdrawrects(uint16_t color) {
  int16_t x;
  fillScreen(ST7735_BLACK);
  for (x = 0; x < _width; x+=6) {
    drawRect(_width/2 -x/2, _height/2 -x/2 , x, x, color);
  }
}
void testfillrects(uint16_t color1, uint16_t color2) {
  int16_t x;
  fillScreen(ST7735_BLACK);
  for (x = _width - 1; x > 6; x -= 6) {
    fillRect(_width/2 -x/2, _height/2 -x/2 , x, x, color1);
    drawRect(_width/2 -x/2, _height/2 -x/2 , x, x, color2);
  }
}
void testfillcircles(uint8_t radius, uint16_t color) {
  int16_t x, y;
  for (x = radius; x < _width; x += radius * 2) {
    for (y = radius; y < _height; y += radius * 2) {
      fillCircle(x, y, radius, color);
    }
  }
}
void testdrawcircles(uint8_t radius, uint16_t color) {
  int16_t x, y;
  for (x = 0; x < _width + radius; x += radius * 2) {
    for (y = 0; y < _height + radius; y += radius * 2) {
      drawCircle(x, y, radius, color);
    }
  }
}
void testroundrects() {
  int8_t i, t;
  uint16_t color = 100;
  fillScreen(ST7735_BLACK);
  for(t = 0 ; t <= 4; t += 1) {
    uint8_t x = 0, y = 0, w = _width - 2, h = _height - 2;
    for(i = 0 ; i <= 16; i++) {
      drawRoundRect(x, y, w, h, 5, color);
      x += 2;
      y += 3;
      w -= 4;
      h -= 6;
      color += 1100;
    }
    color += 100;
  }
}
void testtriangles() {
  uint8_t t, w, x, y, z;
  uint16_t color = 0xF800;
  fillScreen(ST7735_BLACK);
  w = _width/2, x = _height - 1, y = 0, z = _width;
  for(t = 0 ; t <= 15; t++) {
    drawTriangle(w, y, y, x, z, x, color);
    x -= 4;
    y += 4;
    z -= 4;
    color += 100;
  }
}
void mediabuttons() {
  // play
  fillScreen(ST7735_BLACK);
  fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
  delay_ms(500);
  // pause
  fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);
  fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);
  fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);
  delay_ms(500);
  // play color
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
  delay_ms(50);
  // pause color
  fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);
  fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);
  // play color
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);
}


/*
                         Main application
 */
int main(void)
{
  // setup_oscillator(OSC_8MHZ);                         // Set internal oscillator to 8MHz
  //setup_adc_ports(NO_ANALOGS);                        // Configure AN pins as digital
  TFT_BlackTab_Initialize();
  fillScreen(ST7735_BLACK);
  drawtext(0, 5, txt, ST7735_WHITE, ST7735_BLACK, 1);
  setTextWrap(false);
  strcpy (txt, "Hello World!");
  drawtext(0, 30, txt, ST7735_RED, ST7735_BLACK, 1);
  drawtext(0, 47, txt, ST7735_YELLOW, ST7735_BLACK, 2);
  drawtext(0, 80, txt, ST7735_MAGENTA, ST7735_BLACK, 3);
  drawtext(0, 120, txt, ST7735_CYAN, ST7735_BLACK, 4);
  delay_ms(5000);
  fillScreen(ST7735_BLACK);
  drawFastHLine(0, 53, _width,  ST7735_WHITE);
  drawFastHLine(0, 106, _width, ST7735_WHITE);
  while(k++ < 20){
    printf(txt,"%02u",k);
    drawtext(59, 25, txt,  ST7735_GREEN, ST7735_BLACK, 1);
    drawtext(54, 75, txt,  ST7735_BLUE,  ST7735_BLACK, 2);
    drawtext(49, 125, txt, ST7735_RED,  ST7735_BLACK, 3);
    delay_ms(500);
  }
  testlines(ST7735_YELLOW);
  delay_ms(1000);
  testfastlines(ST7735_RED, ST7735_BLUE);
  delay_ms(1000);
  testdrawrects(ST7735_GREEN);
  delay_ms(1000);
  testfillrects(ST7735_YELLOW, ST7735_MAGENTA);
  delay_ms(1000);
  fillScreen(ST7735_BLACK);
  testfillcircles(10, ST7735_BLUE);
  testdrawcircles(10, ST7735_WHITE);
  delay_ms(1000);
  testroundrects();
  delay_ms(1000);
  testtriangles();
  delay_ms(1000);
  mediabuttons();
  delay_ms(1000);
  while(TRUE){
    invertDisplay(true);
    delay_ms(500);
    invertDisplay(false);
    delay_ms(500);
  }
  
    return 1;
}
/**
 End of File
*/

