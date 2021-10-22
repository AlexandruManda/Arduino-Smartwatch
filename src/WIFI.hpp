#pragma once
#include <Arduino.h>

namespace WIFI {
  void initialize();
  void print(String latitude, String longitude, String acceleration);
}
