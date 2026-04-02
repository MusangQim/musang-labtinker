/*-Ju$t-NoT3s-
Draw simple shapes guna pixels
Fikir cara grid thinking - pixel ni mcm LEGO BLOCK
guna BITMAPS to draw image efficient
*/
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void heart_shape()
{
  /* 
  Remember the visual look like this
  y0: . # # . # # .     - Top
  y1: # # # # # # #     - Middle
  y2: # # # # # # #     - Middle
  y3: . # # # # # .     - Bottom
  y4: . . # # # . .     - Bottom
  y5: . . . # . . .     - Bottom
  */

  int startX;
  int startY;
  int i;

  startX = 61;
  startY = 29;

  u8g2.clearBuffer();
  // Top Part (y0) *refer visual kat atas
  u8g2.drawPixel(startX + 1, startY + 0);
  u8g2.drawPixel(startX + 2, startY + 0);
  u8g2.drawPixel(startX + 4, startY + 0);
  u8g2.drawPixel(startX + 5, startY + 0);

  // Middle Part (y1) and (y2)
  i = 0;
  while (i <= 5)
  {
    u8g2.drawPixel(startX + i, startY + 1); // (y1) x-axis from 0 --> 5 full Row
    i++;
  }
  i = 0;
  while (i <= 5)
  {
    u8g2.drawPixel(startX + i, startY + 2); // (y2) x-axis from 0 --> 5 full Row
    i++;
  }

  // Bottom Part
  i = 1;
  while (i <= 4)
  {
    u8g2.drawPixel(startX + i, startY + 3); // (y3) x-axis from 1 --> 4 ON
    i++;
  }
  i = 2;
  while (i <= 3)
  {
    u8g2.drawPixel(startX + i, startY + 4); // (y4) x-axis from 2 --> 3 ON
    i++;
  }
  u8g2.drawPixel(startX + 3, startY + 5); // (y5) x-axis 3 ON
  u8g2.sendBuffer();
}

void setup() 
{
  u8g2.begin();
}

void loop() 
{
  heart_shape();
}
