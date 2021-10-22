#include "SIM.hpp"
#include <SoftwareSerial.h>
SoftwareSerial gsm(11, 10);
namespace SIM {
void initialize() {
  //Begin serial communication with Arduino and SIM800L
  gsm.begin(9600);
  Serial.println("Initializing...");
  delay(1000);


  gsm.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  gsm.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  gsm.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  gsm.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
}

void testSms(){
  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  gsm.println("AT+CMGS=\"+33755797012\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  gsm.print("Hello"); //text content
  updateSerial();
  gsm.write(26);
}

void SOSmessage(String latitude,String longitude){
  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  gsm.println("AT+CMGS=\"+33755797012\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  gsm.println("Emergency message !!"); //text content
  updateSerial();
  gsm.println("Latitude:"+latitude); //text content
  updateSerial();
   gsm.println("Longitude:"+longitude); //text content
  updateSerial();
  gsm.write(26);
}
void testCall(){
  gsm.println("ATD+ +33755797012;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();
}

void updateSerial() {
  delay(500);
  gsm.listen();
  while (gsm.available()>0)
  {
    Serial.write(gsm.read());//Forward what Serial received to Software Serial Port
  }
}


}
