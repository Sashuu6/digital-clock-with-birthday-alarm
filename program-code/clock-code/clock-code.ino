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

DS3231  rtc(SDA, SCL); // Initializing RTC module

void setup() {
  Serial.begin(115200); // Initialize Serial Monitor
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
  display.println("Simple Code");
  display.setCursor(0,10);
  display.println("Simple Code");
  display.display();

  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  // Shows the date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Shows the time
  Serial.println(rtc.getTimeStr());
  // Wait one second before repeating :)
  delay (1000);
}
