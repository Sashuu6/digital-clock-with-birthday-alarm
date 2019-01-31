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

String current_day;
String current_date;
String current_time;
String current_temperature;
String your_birthday = "06.02";
String temp_date = "00.00";

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // OLED
  display.display(); //initialize display
  display.clearDisplay(); //clear display
}

void loop() {
  int i=0;
  int count=0;
  rtc.begin(); // Initialize the rtc object
  
  current_day = rtc.getDOWStr();
  current_date = rtc.getDateStr();
  current_time = rtc.getTimeStr();
  current_temperature = rtc.getTemp();

  while(i<=4) {
    temp_date[i] = current_date[i];
    i++;
    if(temp_date[i] == your_birthday[i]){
      count++;
    }
  }
  display.clearDisplay();
  display.display();
  display.setTextSize(1); // setting text size
  display.setTextColor(WHITE); // setting text color
  display.setCursor(0,0); // setting position for OLED display
  display.print(current_time);
  display.print(" ");
  display.println(current_day);
  display.setCursor(0,10);
  display.print(current_date);
  display.print(" ");
  display.print(current_temperature);
  display.print(" C");

  //Printing all the stuff on the serial monitor
  // Shows the day
  Serial.print("Day: ");
  Serial.print(current_day);
  Serial.print(" ");
  
  // Shows the date
  Serial.print("Date: ");
  Serial.print(current_date);
  Serial.print(" ");
  
  // Shows the time
  Serial.print("Time: ");
  Serial.print(current_time);
  Serial.print(" ");
  
  //Show Temperature
  Serial.print("Temperature: ");
  Serial.println(current_temperature);

  display.setCursor(0,20);
  if(count == 5) { // Set your birthday date here
    display.print("Happy birthday");
    Serial.print(" ");
    Serial.println("Happy birthday");
  }
  display.display(); 
  
  delay (500);
}
