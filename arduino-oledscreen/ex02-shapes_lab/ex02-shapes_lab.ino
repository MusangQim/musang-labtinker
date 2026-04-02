/*
  This for shape:
    Line
    Rectangle
    Circle
*/

#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() 
{
  u8g2.begin();
}

void loop() 
{
  // --------Draw Outline and Fill--------------
  /* 
    Outline = drawCircle(x, y, radius)
    Filled = drawDisc(x, y, radius)
  */
  u8g2.clearBuffer();
  u8g2.drawCircle(32, 50, 10);
  u8g2.drawDisc(96, 50, 10);
  u8g2.sendBuffer();
  delay(5000);

  // --------Draw Outline and Fill--------------
  /*
    Outline = drawFrame(x, y, width, height)
    Filled = drawBox (x, y , width, height)
  */
  u8g2.clearBuffer();
  u8g2.drawFrame(10, 10, 50, 30);
  u8g2.drawBox(70, 10, 40, 20);
  u8g2.sendBuffer();
  delay(5000);

  // --------Draw Line--------------
  /*
    Line = drawLine(x0, y0, x1, y1) 
    (x0, y0) = initial
    (x1, y1) = end
  */
  u8g2.clearBuffer();
  u8g2.drawLine(0, 0, 64, 32);
  u8g2.sendBuffer();
  delay(5000);

}
