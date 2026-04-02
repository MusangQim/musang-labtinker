/*-Ju$t-NoT3s-
NI YANG PRO + CLEAN + EASY TO UPDATE
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

const char* menu_items[] = 
{
  "1) Start",
  "2) Settings",
  "3) About",
};

const int total_items = 3; //pastikan check variable menu_items

// f(x) draw one menu item clean
void draw_menuitems(int index, int y)
{
  int box_width;
  int box_height;

  box_width = 100;
  box_height = 14;
  if (index == selected)
  {
    // Highlight Box using white colour
    u8g2.setDrawColor(1);
    u8g2.drawBox(5, y - 10, box_width, box_height);

    // Text in Black
    u8g2.setDrawColor(0);
    u8g2.setCursor(10, y);
    u8g2.print(menu_items[index]);
  }
  else
  {
    // Yang tak select -> White colour
    u8g2.setDrawColor(1);
    u8g2.setCursor(10, y);
    u8g2.print(menu_items[index]);
  }
}

void draw_menu()
{
  int i;
  int y;
  u8g2.clearBuffer();

  y = 20;
  i = 0;
  while(i < total_items)
  {
    draw_menuitems(i, y);
    y += 15;
    i++;
  }
  u8g2.sendBuffer();
}

void setup() 
{
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
}

void loop()
{
  char  c;
  if (Serial.available())
  {
    c = Serial.read();
    if (c == 'w')
    {
      selected--;
      if (selected < 0)
      {
        selected = total_items - 1;
      }
    }
    if (c =='s')
    {
      selected++;
      if (selected >= total_items)
      {
        selected = 0;
      }
    }
  }
  draw_menu();
  delay(30);
}