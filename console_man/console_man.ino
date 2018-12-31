// The console command to a Yun over the wifi using the command: ssh root@10.0.0.100 'telnet localhost 6571'
//This script allows you to send data from a linux ssh to the arduino board via 'Console.read()' command to receive data and therefore control the light pin
//Can we send data back over to the Console from the arduino atmega? Read on that

//Alternative to Console/ssh method, we could use the YunServer.h and YunClient.h libraries, read: https://blog.arduino.cc/2013/09/05/hands-on-the-arduino-yuns-bridge/

#include <Console.h>

const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Bridge.begin();
  Console.begin(); 

  while (!Console){
    ; // wait for Console port to connect.
  }
  Console.println("You're connected to the Console!!!!");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Console.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Console.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
  delay(100);
}
