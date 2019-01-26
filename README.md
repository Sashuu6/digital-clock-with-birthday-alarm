# digital clock with birthday alarm
The digital clock with birthday alarm is a DYI alarm built using Arduino UNO, Adafruit OLED and DS 3231 RTC module.

# Instructions

First we will setup the date and time to the RTC module.

1. Download the RTC module library from [this link](http://www.rinkydinkelectronics.com/download.php?f=DS3231.zip).
2. Add the library to the Arduino IDE.
3. Connect the coin cell to the RTC module.
4. Connect SDA to UNO's A4, SCL to UNO's A5, VCC to UNO's 5v and GND to UNO's GND.
5. Open the code present at program-code/code-to-set-date-time/code-to-set-date-time.ino.
6. Edit according to the comments present in the code.
7. Run it to set the date and time.

Note: Run the program only once. This code sets the date and time to the RTC module. 

Now, we will install Adafruit OLED library and run the clock code

1. Install Adafruit GFX library and Adafruit SSD1306 library from manage libraries.
2. Edit the code present at program-code/clock-code/clock-code.ino to set the birthday date.
3. Run the above code to start the clock.