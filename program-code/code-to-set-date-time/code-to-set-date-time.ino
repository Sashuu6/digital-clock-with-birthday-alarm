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
// Created On: 26 Jan 2019
// Revision: 5
// Last Edited: 31 Jan 2019

// Arduino Uno/2009:
// ----------------------
// DS3231:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//          SCL pin   -> Arduino Analog 5 or the dedicated SCL pin

// This code will help you to set date and time to the RTC module.

#include <DS3231.h> // RTC module library header file

DS3231  rtc(SDA, SCL); // Init the DS3231 using the hardware interface

void setup()
{
  Serial.begin(9600); // Setup Serial connection
  rtc.begin(); // Initialize the rtc object
  rtc.setDOW(THURSDAY); // Set Day-of-Week to your current day
  rtc.setTime(18, 16, 52); // Set the time to current time. Set the time in 24-hours
  rtc.setDate(31, 1, 2019); // Set the date to your current date
}

void loop()
{
  // Shows the Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Shows the date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  
  // Shows the time
  Serial.println(rtc.getTimeStr());
  
  delay (500);   // Wait one second before repeating
}
