/* Author: Taariq Ghansar

Task:
  Set up a serial port to pass data between an XBee Shield
  and the serial monitor.

Aim:
  Would like to see the Yun as the receiver

Test Mode:
  Application Transparent

Explanation:
  The XBee Shield makes all of the connections you'll need
  between Arduino and XBee. Arduino pins 0 and 1 shall pass the 
  XBee incoming bytes (Application Transparent) to the Arduino 32U4
  micro-controller of the Yun. Hence, it can now easily pass the data
  over to the console using Bridge and therefore be retrieved over the
  serial monitor via WiFi.

Next Version of this file should:
  Establish to publish via MQTT once I have learnt to do this on the Arduino Yun;
  or
  Write or write append the data as a text file to the Micro-SD of the Arduino Yun;
  or
  Publish the data using REST commands over to the web/local network.
  
*/

// Leonardo Serial  is the USB port (Xbee Explorer)
// Leonardo Serial1 is pins 0 and 1

#include <Console.h>//Report to serial monitor
#include <Bridge.h>

#include <SoftwareSerial.h>             // The arduino Yun does not have a vacant Serial to use for XBee communication,
                                        //therefore rely on a user made serial using SoftwareSerial
SoftwareSerial mySerial(8, 9); // RX, TX

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  
  //Serial1.begin(9600);  //XBee/UART1/pins 0 and 1
  ////Serial.begin(9600);   //USB
  
  Bridge.begin();
  Console.begin();
  
  while(!Console){;}
  Console.println("Hello");
  delay(100);

  mySerial.begin(9600);                 //XBee is set to 9600 bits per second (Baud Rate)

  Console.println("mySerial started");
  delay(100);
}

void loop()
{/*
  if (Serial.available()) //USB
    { // If data comes in from serial monitor, send it out to XBee
    Serial1.write(Serial.read()); //XBee/UART1/pins 0 and 1 
  
    }*/
  if (mySerial.available())               //XBee UART1 pins 0 and 1 re-routed to 8 and 9 (re-wired) for compatibility of the Libelium shield,
                                          //the RX and TX sends through the former pins, I made use of alternative pins.
    {                                   // If data comes in from XBee, send it out to serial monitor.
      //delay(50);
      char c = mySerial.read();       //Return a character that was received on the RX pin of the software serial port. Required to send all data one character at a time.
      Console.write(c);              //Report retrieved data to Console port (useful for monitoring and debugging communication)
      delay(10);
      //Console.write("iteration");
      //delay(10);
    }
}

/*
//Useful code for telling time, code is from another source: https://blog.arduino.cc/2013/09/05/hands-on-the-arduino-yuns-bridge/

  // get the current time:
  Process timeNow;
  String timeString;
  
  timeNow.runShellCommand("date");
  while(timeNow.available()) {
    char c = timeNow.read();
    timeString += c;
  }
*/
