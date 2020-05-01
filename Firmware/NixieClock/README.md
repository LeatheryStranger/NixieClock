# NixieClock Firmware
## Overview
This little sketch pulls from a small list of projects to create a clock that should maintain the correct time for years thanks to the battery operated RTC module.  In order to set that to the correct time, Please go to the setup folder to find the code I used to do that (wifi NTP setup).  It takes UTC unix time from the RTC, then using the excellent Timezone library from JChristesens, converts it to the local time.  The parses the time into individual digits and outputs those to the tubes.  Every 15 minutes or so it cycles through all the digits in the clock to clean any deposits off of them.  

## Dependencies
* RTCLib - For this project I used a [DS3231](https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/overview) from Adafruit, which uses this [RTCLib](https://github.com/adafruit/RTClib)
* Timezone - You can find JChristesens Timezone library [here](https://github.com/JChristensen/Timezone)
* SerialNixieDriver - Excellent little library, but afaik only useful if you use the designs for the [Serial Nixie Driver](https://github.com/tonyp7/SerialNixieDriver)
