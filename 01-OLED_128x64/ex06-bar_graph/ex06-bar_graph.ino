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

  /*
  1) Draw rectangle outline
    u8g2.clearBuffer();
    u8g2.drawFrame(bar_x, bar_y, bar_width, bar_height);
    u8g2.sendBuffer();
  */

  /*
  2) Fill partially
    u8g2.clearBuffer();
    u8g2.drawBox(bar_x, bar_y, (bar_width * fillAmount) / 100, bar_height);
    u8g2.sendBuffer();
  */

  /*
  3) Animate
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
  */

  /*
    boleh je guna for loops
    for(int fill = 0, fill <= 100; fill++)
    {
      u8g2.clearBuffer();
      u8g2.drawFrame(bar_x, bar_y, bar_width, bar_height);
      u8g2.drawBox(bar_x, bar_y, (bar_width * fill) / 100, bar_height);
      u8g2.sendBuffer();
      delay(30);
    }
  */

  //4) Additional Feature
  int fill;
  for(fill = 0; fill <= 100; fill++)
  {
    u8g2.clearBuffer();
    u8g2.drawFrame(bar_x, bar_y, bar_width, bar_height);
    u8g2.drawBox(bar_x, bar_y, (bar_width * fill) / 100, bar_height);

    char percentText[6];
    sprintf(percentText, "%d%%", fill);
    u8g2.setCursor(bar_x, bar_y - 2);//(62, 28);//(bar_x + bar_width + 6, bar_y + bar_height - 1);
    u8g2.print(percentText);

    u8g2.sendBuffer();
    delay(30);
  }
}

void setup() 
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
}

void loop() 
{
  bar_graph();
}
