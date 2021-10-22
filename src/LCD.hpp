#pragma once
#include <Arduino.h>

namespace LCD{

  void initialize();
  void displayText(long hour, long minute, long year, long month, long day, String latitude, String longitude);
}
