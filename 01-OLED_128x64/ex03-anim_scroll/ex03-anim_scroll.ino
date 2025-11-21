#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int x = 128; //start dari Kanan

void setup() 
{
  u8g2.begin();
}

void loop() 
{
  u8g2.clearBuffer();

  
  u8g2.sendBuffer();

}
