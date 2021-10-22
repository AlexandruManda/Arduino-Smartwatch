#include "FallDetection.hpp"

long lastDisplayTime;
float x, y, z;
float x_off, y_off, z_off;
namespace FallDetection {
void initialize()
{
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

boolean detection () {
  for (int i = 0; i < 100; i++) {
    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(x, y, z);
      x = x * 256;
      y = y * 256;
      z = z * 256;
      //      x_acc = x_acc + x;
      //      y_acc = y_acc + y;
      //      z_acc = z_acc + z;
    }
  }
  // compute the offset to substract from real time value
  x_off = x / 100;
  y_off = y / 100;
  z_off = z / 100;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    x = x * 256 - x_off;
    y = y * 256 - y_off;
    z = z * 256 - z_off;

    float at = sqrt(x * x + y * y + z * z);
    if (at < 50) {
      return true;
    }
    else {
      return false;
    }
  }
}

void displayAccValues() {
  if (IMU.accelerationAvailable()) {
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}

String getTotalAcceleration() {
  float at;
  for (int i = 0; i < 100; i++) {
    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(x, y, z);
      x = x * 256;
      y = y * 256;
      z = z * 256;
      //      x_acc = x_acc + x;
      //      y_acc = y_acc + y;
      //      z_acc = z_acc + z;
    }
  }
  // compute the offset to substract from real time value
  x_off = x / 100;
  y_off = y / 100;
  z_off = z / 100;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    x = x * 256 - x_off;
    y = y * 256 - y_off;
    z = z * 256 - z_off;

    at = sqrt(x * x + y * y + z * z);
  }
  return String(at);
}
}
