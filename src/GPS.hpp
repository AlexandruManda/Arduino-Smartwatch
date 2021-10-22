#pragma once
#include <Arduino.h>

namespace GPS{
    void initialize();
    void printLocation();
    void printTime();
    void getTime(long&hour,long&minute);
    void getDate(long&year,long&month,long&day);
    String getLatitude();
    String getLongitude();
    void printDate();
    void encode();
    void updateSerial();
}
