/*-Ju$t-NoT3s-
So this one using Potentiometer:
  1) Read potentiometer
  2) Convert ADC
  3) Display real-time in OLED
  4) Clean the UI
*/
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int sensorPin = 1;   // ESP32-C3 uses GPIO2 for ADC
int sensorValue = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);
}
