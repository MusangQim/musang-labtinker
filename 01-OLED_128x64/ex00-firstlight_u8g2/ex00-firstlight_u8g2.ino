#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup()
{
  u8g2.begin();
}

void loop()
{
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 20, "Hello World");

    u8g2.setFont(u8g2_font_courB14_tr);
    u8g2.drawStr(0, 40, "Hello World");
    
    u8g2.setFont(u8g2_font_6x10_tr);
    u8g2.drawStr(0, 60, "Hello World");

    u8g2.sendBuffer();
    delay(2000);
}