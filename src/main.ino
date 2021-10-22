#include"FallDetection.hpp"
#include "GPS.hpp"
#include "LCD.hpp"
#include "SIM.hpp"
#include "WIFI.hpp"

long hour, minute;
long year, month, day;
String latitude, longitude;
String at;
unsigned long time_now = 0;
unsigned long time2=0,time3=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  FallDetection::initialize();
  GPS::initialize();
  SIM::initialize();
  LCD::initialize();
//    WIFI::initialize();
}

void loop() {
  GPS::updateSerial();
  // put your main code here, to run repeatedly:
//  
      boolean Ok=FallDetection::detection(); 

      if(Ok==true){
        SIM::SOSmessage(latitude,longitude);
        SIM::updateSerial();
          SIM::testCall();
//         
      }
      
//          SIM::testCall();
  //    FallDetection::displayAccValues();
  //getting the values for total acceleration

//  SIM::updateSerial();
//  at=FallDetection::getTotalAcceleration();
//     Serial.println(at);


if(millis()>=time_now+1000){
  time_now+=1000;
  //getting latitude and longitude
  //getting time and date
  GPS::getTime(hour, minute);
  GPS::getDate(year, month, day);
  latitude = GPS::getLatitude();
  longitude = GPS::getLongitude();
  LCD::displayText(hour, minute, year, month, day, latitude, longitude);
//      WIFI::print(latitude,longitude,at);

}
      }
