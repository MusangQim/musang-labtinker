/*-Ju$t-NoT3s-
Create bar graph:
  1) Draw rectangle outline aka bar container
  2) Fill partially aka progress effect
  3) Animate aka Loading effect
*/
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void bar_graph()
{
  int bar_x = 10;
  int bar_y = 30;
  int bar_width = 100;
  int bar_height = 10;
  int fillAmount = 50;

  //1) Draw rectangle outline
  //u8g2.clearBuffer();
  //u8g2.drawFrame(bar_x, bar_y, bar_width, bar_height);
  //u8g2.sendBuffer();

  //2) Fill partially
  //u8g2.drawBox(bar_x, bar_y, (bar_width * fillAmount) / 100, bar_height);
  //u8g2.sendBuffer();

  //3) Animate
  int fill = 0;
  while (fill <= 100)
  {
    u8g2.clearBuffer();
    u8g2.drawFrame(bar_x, bar_y, bar_width, bar_height);
    u8g2.drawBox(bar_x, bar_y, (bar_width * fill) / 100, bar_height);
    u8g2.sendBuffer();
    delay(30); //speed of loading
    fill++;
  } 
}

void setup() 
{
  u8g2.begin();
}

void loop() 
{
  bar_graph();
}
