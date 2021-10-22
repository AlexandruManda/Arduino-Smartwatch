# Introduction
 
The idea of this project is to create a smartwatch which is able to get the GPS location coordinates and sends the data through GSM as an emergency message in case of a fall detection and also a phone call. With the use of Arduino Uno WiFi REV2 board, we could use the builtin accelerometer and it also provides support for WiFi and Bluetooth conection. The objective of the project could be to help seniors who are still considered as active to keep in track their activity. The idea is working also for the people far from their family and in case of an emergency they will be able to know if something will happen and they will be alerted.

# Modules used
 External modules that were used in the project:
| Name  | Description|
| ------------- | ------------- |
| SIM800L  | Allows voice calls, messages   |
| Arduino Uno Wifi Rev2  | Microcontroller board with builtin accelerometer, Bluetooth, Wifi module  |
| 2x Lipo 4.2V Batteries | Used for powering the smartwatch |
| ADAFRUIT 0.96" module | Used for displaying the current date, time and GPS location|
| GPS GT-U7 module | Used for getting the real time,date and location|


Each of the modules are communicating through different protocols. For example the GPS module is using the UART communication. The OLED display is using the I2C protocol and you need to specify the address of the device in case you want to connect multiple modules on the same SDA and SCL pins, but in this case only the OLED module was connected to the pins. 

# Features
![image](https://user-images.githubusercontent.com/82172947/138481071-a1365348-219b-4688-95ed-05c1ecc931c2.png)
- Displaying the real time and date
- Fall detection (with the use of accelerometer)
- SOS message and call
- Geolocalisation
- Battery charging

# Demo Video

https://user-images.githubusercontent.com/82172947/138486685-04502cb6-4148-4e59-b15c-54baafaf6eb3.mp4

