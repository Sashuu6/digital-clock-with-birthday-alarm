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
// Last Edited: 31 Jan 2019

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
String your_birthday = "05.11";
String temp_date = "00.00";
int disp_screen = 0;
int button_pin = 8;
boolean button_value = 0;

void setup() {
  pinMode(button_pin, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // OLED
  display.display(); //initialize display
  display.clearDisplay(); //clear display
  Serial.begin(9600); // Initialize Serial Monitor
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

  button_value = digitalRead(button_pin);
  if(button_value == 1) {
    disp_screen++;
    if(disp_screen>2) {
      disp_screen = 0;
    }
  }
  
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE); // setting text color
  if(disp_screen == 0) {
    display.setTextSize(2); // setting text size
    display.setCursor(17,0); // setting position for OLED display
    display.print(current_time);
    display.setTextSize(1.5);
    display.setCursor(10,20);
    display.println(current_day);
    display.setCursor(95,20);
    if(count == 5) {
      display.println(">>1<<");
    }
    else {
      display.println(">>0<<");
    }
  }
  else if(disp_screen == 1) {
    display.setTextSize(2); // setting text size
    display.setCursor(0,0); // setting position for OLED display
    display.print(current_date);
    display.setTextSize(1.5);
    display.setCursor(40,20);
    display.print(current_temperature);
    display.print(" C");
  }
  else {
    if(count == 5) {
      display.setTextSize(2); // setting text size
      display.setCursor(0,0); // setting position for OLED display
      display.println("Happy Bday");
      display.println("Myself !!");
      display.display();
    }
    else {
      display.setTextSize(2); // setting text size
      display.setCursor(10,10); // setting position for OLED display
      display.println("No alerts");
    }
  }

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
  Serial.print(current_temperature);
  Serial.print(" ");

  //Show Screen number
  Serial.print("Screen number: ");
  Serial.println(disp_screen);
  //Show birthday or not
  if(count == 5) {
    Serial.print(" ");
    Serial.println("Happy Bday Myself");
  }
  display.display(); 
  
  delay (500);
}
