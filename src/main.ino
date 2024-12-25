#include "lcd_display.ino"
#include "wifi_setup.ino"
#include "sensor_data.ino"

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(led, OUTPUT);
  
  setupESP8266();
  lcd.begin(16, 2);
}

void loop() {
  anydata();
  delay(10000);
}
