#include"GPS.hpp"
#include "SoftwareSerial.h"
#include "TinyGPS++.h"
#include <String.h>

SoftwareSerial serial_connection(1, 0);
TinyGPSPlus gps;
int Year;
byte Month;
byte Day;
byte Hour;
byte Minute;
byte Second;
//long scale=10000000UL;
namespace GPS {

void initialize() {
  serial_connection.begin(9600);
  Serial.println("GPS Start");

}
void printLocation() {
  if (gps.location.isUpdated()) {
    //        Serial.println("Satelite Count:");
    //        Serial.println(gps.satellites.value());
    Serial.println("Latitude: ");
    Serial.println(gps.location.lat(), 7);
    Serial.println("Longitude: ");
    Serial.println(gps.location.lng(), 7);
  }
}

void printDate() {
  if (gps.date.isValid())
  {
    Serial.print("  Date:  ");
    Serial.print(gps.date.year());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.day());
  }
}
void printTime() {
  if (gps.time.isValid()) {
    if (gps.time.hour() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.hour() + 2);
    Serial.print(F(":"));
    if (gps.time.minute() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10)
      Serial.print(F("0"));
    Serial.println(gps.time.second());
  }
}
void getTime(long&hour, long&minute) {
  if (gps.time.isValid()) {
    hour = gps.time.hour() + 2;
    if (hour > 24) {
      hour = hour - 24;
    }
    minute = gps.time.minute();
  }
}
void getDate(long&year, long&month, long&day) {
  if (gps.date.isValid()) {
    year = gps.date.year();
    month = gps.date.month();
    day = gps.date.day();
  }
}
String getLatitude() {
  String lat;
  if (gps.location.isUpdated()) {
    lat = String(gps.location.lat(), 7);
    return lat;
  }
}

String getLongitude() {
  String longitude;
  if (gps.location.isUpdated()) {
    longitude=String(gps.location.lng(),7);
     return longitude;
  }
}
//        latitude = gps.location.rawLat().deg*scale+gps.location.rawLat().billionths/100UL;
//        if(gps.location.rawLat().negative)
//          latitude=-latitude;
//        longitude = gps.location.rawLng().deg*scale+gps.location.rawLng().billionths/100UL;
//        if(gps.location.rawLng().negative)
//          longitude=-longitude;
void updateSerial() {
  serial_connection.listen();
  while (serial_connection.available() > 0)
  {
    gps.encode(serial_connection.read());
//    Serial.write(serial_connection.read());//Forward what Serial received to Software Serial Port
  }
  
}
}
