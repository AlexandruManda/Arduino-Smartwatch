#pragma once
#include <Arduino.h>

namespace SIM{
  void initialize();
  void updateSerial();
  void testSms();
  void testCall();
  void SOSmessage(String latitude,String longitude);
}
