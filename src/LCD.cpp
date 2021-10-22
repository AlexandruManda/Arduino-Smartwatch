#include"LCD.hpp"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

namespace LCD {
void initialize() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  //      testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  //      display.clearDisplay();
        delay(2000);
}

void displayText(long hour, long minute, long year, long month, long day, String latitude, String longitude) {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);
  if (hour < 10)
    display.print(0);
  display.print(hour);
  display.print(F(":"));
  if (minute < 10)
    display.print(0);
  display.print(minute);
  display.println(" ");
  display.setTextSize(1);
  display.print("\n");
  display.print(year);
  display.print(F("/"));
  display.print(month);
  display.print(F("/"));
  display.print(day);
  display.println(" ");
  display.setTextSize(1);
  display.print("\n");
  display.print(F("Latitude: "));
  display.print(latitude);
  display.print("\n");
  display.print(F("Longitude: "));
  display.print(longitude);
  display.display();
//      delay(800);
}
}
