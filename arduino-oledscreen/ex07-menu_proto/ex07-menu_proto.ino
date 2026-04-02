/*-Ju$t-NoT3s-
so this one create Menu ProtoType:
  - 3 option menu
  - selection bergerak
  - highlight select item
  - display guna U8g2
*/
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int selected = 0;

//1) Option Menu
void draw_menu()
{
  u8g2.clearBuffer();

  int box_width;
  int box_height;
  int box_highlight;

  box_width = 100;
  box_height = 14;
  box_highlight = 20 + (selected * 15) - 10;

  u8g2.setDrawColor(1); //warna putih
  u8g2.drawBox(5, box_highlight, box_width, box_height);
  
  u8g2.setDrawColor(0); //dlm highlight
  if (selected == 0)
  {
    u8g2.setCursor(10, 20);
    u8g2.print("1) Start");
  }

  if (selected == 1)
  {
    u8g2.setCursor(10, 35);
    u8g2.print("2) Settings");
  }
  if (selected == 2)
  {
    u8g2.setCursor(10, 50);
    u8g2.print("3) About");
  }

  u8g2.setDrawColor(1); //reset normal white text
  if (selected != 0)
  {
    u8g2.setCursor(10, 20);
    u8g2.print("1) Start");
  }

  if (selected != 1)
  {
    u8g2.setCursor(10, 35);
    u8g2.print("2) Settings");
  }
  if (selected != 2)
  {
    u8g2.setCursor(10, 50);
    u8g2.print("3) About");
  }

  u8g2.sendBuffer();
}

void setup() 
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
  Serial.begin(9600);
}

void loop() 
{
  char c;
  if (Serial.available())
  {
    c = Serial.read();
    if (c == 'w')
    {
      selected--;
      if (selected < 0)
      {
        selected = 2;
      }
    }
    if (c == 's')
    {
      selected++;
      if (selected > 2)
      {
        selected = 0;
      }
    }
  }
  draw_menu();
  delay(50);
}