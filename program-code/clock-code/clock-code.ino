//                                      $$\                            $$$$$$\  
//                                      $$ |                          $$  __$$\ 
//         $$$$$$$\  $$$$$$\   $$$$$$$\ $$$$$$$\  $$\   $$\ $$\   $$\ $$ /  \__|
//        $$  _____| \____$$\ $$  _____|$$  __$$\ $$ |  $$ |$$ |  $$ |$$$$$$$\  
//        \$$$$$$\   $$$$$$$ |\$$$$$$\  $$ |  $$ |$$ |  $$ |$$ |  $$ |$$  __$$\ 
//         \____$$\ $$  __$$ | \____$$\ $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ /  $$ |
//        $$$$$$$  |\$$$$$$$ |$$$$$$$  |$$ |  $$ |\$$$$$$  |\$$$$$$  | $$$$$$  |
//        \_______/  \_______|\_______/ \__|  \__| \______/  \______/  \______/ 
//
// Author: Sashwat K
// Created On: 17 Jan 2019
// Revision: 1
// Last Edited: 17 Jan 2019

#include <SPI.h>  // adafruit display driver header file
#include <Wire.h> // adafruit display driver header file
#include <Adafruit_GFX.h> // adafruit display driver header file
#include <Adafruit_SSD1306.h> // adafruit display model header file
#include <DS3231.h> // RTC module library header file

#define OLED_RESET 4 //OLED
Adafruit_SSD1306 display(OLED_RESET); //OLED

DS3231  rtc(SDA, SCL); // Init the DS3231 using the hardware interface

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // OLED
  display.display(); //initialize display
  display.clearDisplay(); //clear display
  delay(1000);
}

void loop() {
  rtc.begin(); // Initialize the rtc object
  display.clearDisplay();
  display.display();
  display.setTextSize(1); // setting text size
  display.setTextColor(WHITE); // setting text color
  display.setCursor(0,0); // setting position for OLED display
  display.print(rtc.getTimeStr());
  display.print(" ");
  display.println(rtc.getDOWStr());
  display.setCursor(0,10);
  display.println(rtc.getDateStr());
  display.setCursor(0,20);
  display.println("Happy birthday Sashuu");
  display.display();

  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  // Shows the date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Shows the time
  Serial.println(rtc.getTimeStr());
  
  delay (500);
}
