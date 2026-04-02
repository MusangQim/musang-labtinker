/*-Ju$t-NoT3s-
kalau multiple animations occur at the same time, dia akan jittering
Animation Cycle:
  1) clearBuff
  2) draw (text atau shape)
  3) sendBuff
  4) update Position x and y
  5) delay untuk control speed 

! Delay makin kecik , makin banyak fps (frame per second) = animation CANTEK!!

*/

#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int x = 128; //start dari Kanan
int y = -10;

void setup() 
{
  u8g2.begin();
}

void loop() 
{
  // ------------------Vertical Scroll Animation----------------------------------------
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tr);

  u8g2.drawStr(20, y, "WORLD!");
  u8g2.sendBuffer();

  y++; // Move the object (ke bawah)

  if (y > 64)
  {
    y = -10; //reset dari Atas
  }
  delay (20);
/*
  // ------------------Horizontol Scroll Animation----------------------------------------
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tr); 
  
  u8g2.drawStr(x, 32, "HELLO!");
  u8g2.sendBuffer();

  x--; //Move the object (ke kiri)

  if (x < -u8g2.getStrWidth("HELLO"))
  {
    x = 128;
  }
  delay (15); //control Speed animation
*/
}
