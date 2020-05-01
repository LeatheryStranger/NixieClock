#include <RTClib.h>
#include <Timezone.h>
time_t utc;
time_t local;
DateTime nowish;

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First, Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
Timezone myTZ(myDST, mySTD);

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  delay(3000);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  if (1) {   //rtc.lostPower()
    Serial.println("RTC lost power, lets set the time!");

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  nowish = rtc.now();
  utc = myTZ.toUTC(nowish.unixtime());
  rtc.adjust(utc);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println(nowish.unixtime());
  //printDateTime(utc, "UTC");
  //Serial.print(F(__DATE__));
  //Serial.print("/");
  //Serial.println(F(__TIME__));
  Serial.print("Compiled Time:");
  Serial.print(F(__TIME__));
  Serial.println();
  Serial.println();
  Serial.print("Ajustment Time:");
  Serial.print(nowish.hour(), DEC);
  Serial.print(':');
  Serial.print(nowish.minute(), DEC);
  Serial.print(':');
  Serial.print(nowish.second(), DEC);
  Serial.println();
  Serial.println();
  nowish = rtc.now();
  Serial.print("Current RTC Time:");
  Serial.print(nowish.hour(), DEC);
  Serial.print(':');
  Serial.print(nowish.minute(), DEC);
  Serial.print(':');
  Serial.print(nowish.second(), DEC);
  Serial.println();
  Serial.println();
  local = myTZ.toLocal(nowish.unixtime());
  Serial.print("new local time:");
  printTime(local);
  Serial.println();
  
  delay(3000);
  //Serial.println(printTime(utc));
  //printDate(utc);
  
  
}
const char* printDate(time_t t) {
  char dateString[11];
  char m[4];
  
  strcpy(m, monthShortStr(month(t)));
  sprintf(dateString, "%s %.2d %d", m, day(t), year(t));
  Serial.println(dateString);
  Serial.println();
  return dateString;
}
const char* printTime(time_t t){
  char timeString[8];
  
  sprintf(timeString, "%.2d:%.2d:%.2d", hour(t), minute(t), second(t));
  Serial.print(timeString);
  Serial.println();
  return timeString;
}
