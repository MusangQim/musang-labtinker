/*-Ju$t-NoT3s-
OLED Display = 128 x 64 pixels (X, Y)
...if it half = 64 x 32 pixels (X, Y)
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
  // -----------Centre Alignment----------------
  /*
    For perfect centre use this
    text_width = u8g2.getStrWidth("text");
    Formula:
      centre_x = (128 - text_width) / 2 ---tengah kan X-axis
      centre_y = (64 + font_height) / 2 ---tengah kan Y-axis
    u8g2.drawStr(center_x, 32, "text");
    'agak leceh tapi nnti buat function' --> easy to use
  */
  int text_width;
  int centre_x;
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);

  //First string
  text_width = u8g2.getStrWidth("Hello");
  centre_x = (128 - text_width) / 2;
  u8g2.drawStr(centre_x, 32, "Hello");
  delay(5000);
  u8g2.sendBuffer();

  //Second string
  u8g2.clearBuffer();
  text_width = u8g2.getStrWidth("Friends");
  u8g2.drawStr(centre_x, 32, "Friends");
  delay(5000);
  u8g2.sendBuffer();
  // -----------Baseline Demonstration----------
  /*
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "I am Line 1");
  u8g2.drawStr(0, 20, "I am Line 2");
  u8g2.drawStr(0, 30, "I am Line 3");
  u8g2.drawStr(0, 40, "I am Line 4");
  u8g2.drawStr(0, 50, "I am Line 5");
  u8g2.drawStr(0, 60, "I am Line 6");
  u8g2.sendBuffer();
  */

  // -----------Moving the String---------------
  /*
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(60, 32, "MOVE ME!");
  u8g2.sendBuffer();
  */
}
