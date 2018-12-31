/*Author: Taariq Ghansar
Smart Agriculture Honours Project

Reminder: Please note that this only works with Application Transparent mode.
Refer to other sources to learn API mode and its libraries.
You need to use API mode, unless proven wrong, in order to connect and send the information over to an executable Python script on the Arduino Yun.

And you also need to use the Bridge Library to send the information from the Atmega processor to the Atheros processor.
Therefore, first start learning and using a bridge in order to do the next part.

DO NOT FORGET TO MENTION WHAT EACH LIBRARY DOES AND HOW IT WORKS.
*/

#include <SoftwareSerial.h>
//#include <string.h>
//#include <stdlib.h>    //snprintf()  //itoa()

SoftwareSerial XBee(2, 3);                                  //RX, TX
const int tempSensorPin = A3;                               //Change this to the data pin you are using
int counter = 1;
                                                            //https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
float analogToMilliVolt(float analogValue)                  //This converts the number 0-1023 from the analog to 0-3300mV proportionally
{
  return analogValue * 3300 / 1024;
}

float tempCelcius(float analogValue)
{
  return (analogToMilliVolt(analogValue)- 500)/10;
}

void setup()
{
  XBee.begin(9600);
  Serial.begin(9600);

  while(!Serial)
  {
    ;//Do nothing but wait for serial port to connect. Needed for native USB port only.
  }
  
  Serial.println("Begin");
  delay(100);
}

void loop()
{
  //Function loops

  
  float rawReading = analogRead(tempSensorPin);     //Analogue value between 0 - 1023 (10 bit) value, need to convert to mV and calculate further.
  float temperature = tempCelcius(rawReading);      //Final output value of temperature in degrees Celcius

/*
  //char message[] = "";
  //char strTemperature[7];
  //snprintf(strTemperature, 7, "%f", temperature);

  char strOut[1];
  sprintf(strOut, "%d", counter);
  strcpy(message, strOut);
  
  strcpy(message," Temperature: ");
//  strcpy(message, strTemperature);
*/
  
  Serial.print(counter);
  delay(100);
  Serial.print(" Temp: ");
  delay(100);
  Serial.println(temperature);
  //delay(100);

//  if (Serial.available())
//  { // If data comes in from serial monitor, send it out to XBee
//   XBee.write(Serial.read());
//  }
  
  if (counter >= 10000)
  {
    Serial.println();    
    Serial.end();
  }
  counter++;
  delay(500);
}
