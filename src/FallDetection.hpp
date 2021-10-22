#pragma once

#include <Arduino.h>
#include <Arduino_LSM6DS3.h>
// A module to handle the fall detection using the built in accelerometer
namespace FallDetection {
  void initialize();
  boolean detection ();
  void displayAccValues();
  String getTotalAcceleration();
}
