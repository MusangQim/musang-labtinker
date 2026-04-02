/*-Ju$t-NoT3s-
Need 3 things:
  Position = x and y
  Velocity = how fast it moves using (vx, vy) v = velocity
  Collision detection = kena tepi screen, it will reverse direction
  mcm iklan DVD player

  if x < 0 = from LEFT
  if y < 0 = from TOP
*/

#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int x = 0; // position start from Left
int vx = 2; // horizontol speed

int y = 32; // position start from Middle
int vy = 2; // vertical speed

String text = "HELLO";
int text_width = 0;

void horizontol_bounce()
{
   // -------------------------Horizontol Bounce Loop (x - axis)---------------------
  u8g2.clearBuffer();

  // 1. Draw the text (y-axis fixed, x moves)
  u8g2.drawStr(x, 32, text.c_str()); 

  // 2. Move the text
  x = x + vx;

  // 3. Condition Bounce Left ( 0 = left)
  if (x < 0)
  {
    vx = -vx;
  }

  // 4. Condition Bounce Right ( 128 = right)
  if (x > (128 - text_width)) 
  {
    vx = -vx;
  }
  
  // 5. Send Data and Delay
  u8g2.sendBuffer();
  delay(20);
}

void vertical_bounce()
{
  // -------------------------Vertical Bounce Loop (y - axis)---------------------
  u8g2.clearBuffer();

  // 1. Draw the text (x-axis fixed, y moves)
  u8g2.drawStr(30, y, text.c_str());

  // 2. Move the text
  y += vy;

  // 3. Condition Bounce Top
  if (y < 0)
  {
    vy = -vy;
  }

  // 4. Condition Bounce Bottom
  if (y > 63)
  {
    vy = -vy;
  }

  // 5. Send Data and Delay
  u8g2.sendBuffer();
  delay(20);
}

void full_bounce()
{
    // -------------------------Combination Bounce Loop---------------------
  u8g2.clearBuffer();
  
  u8g2.drawStr(x, y, text.c_str());

  x += vx;
  y += vy;

  if (x < 0 || x > (128 - text_width))
  {
    vx = -vx;
  }
  if (y < 0 || y > 63)
  {
    vy = -vy;
  }

  u8g2.sendBuffer();
  delay(20);
}

void extra_bounce()
{
  static bool firstRun = true;
  static int x, y, vx, vy;
  static int text_width;
  String text = "HELLO";
  
  if (firstRun)
  {
    text_width = u8g2.getStrWidth(text.c_str());
    x = random(0, 128 - text_width);
    y = random(0, 64);
    vx = random(1, 2);
    vy = random(1, 2);

    if (random(0, 2) == 0)
    {
      vx = -vx;
    }
    if (random(0, 2) == 0)
    {
      vy = -vy;
    }

    firstRun = false;
  }
  u8g2.clearBuffer();
  u8g2.drawStr(x, y, text.c_str());

  x += vx;
  y += vy;

  if (x < 0 || x > (128 - text_width))
  {
    vx = -vx;
  }
  if (y < 0 || y > 63)
  {
    vy = -vy;
  }
  u8g2.sendBuffer();
  delay(50);
}

void setup() 
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
  text_width = u8g2.getStrWidth(text.c_str());
}

void loop() 
{
  //horizontol_bounce();
  //vertical_bounce();
  //full_bounce();
  extra_bounce();

}
