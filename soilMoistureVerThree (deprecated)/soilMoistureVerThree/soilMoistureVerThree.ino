/*Author: Taariq Ghansar*/
//Soil Moisture, Temp and Humidity
//Strictly always conform to 3.3V for both sensors!
//Always have atleast 2000 milliseconds difference between each temp and humidity sensing in the loop

#include <string.h>    //strlen() strcat()  
#include <stdlib.h>     //itoa()
#include "DHT.h"      //Temp and Humidity Sensor library from Adafruit

#define DHTPIN 2     // The digital pin for the Temp and Humidity sensor (Digital pin D2)
#define DHTTYPE DHT21   // The type of Sensor: DHT21 (AM2301)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor, not started yet.

const int soilMoistureAnalogPin = A0;   //Select the analog read to the A0 pin.

int value = 0;
char charArray[] = ""; //use this only in sendTempValue()
char temp[] = "";
char soilCharArray[] = ""; 
int i;
int lenOfText;
float h;
float t;
uint16_t c;

/***********Functions for the loop() procedure*****************/

//access the memory to the address of the pointer I assume
void sendValue(char* chars){
  int lenOfText = strlen(chars);
  for(i=0; i<lenOfText; i++ ){
    Serial.print(char(chars[i]));
    delay(50);
  }  
}

void sendTempHumidValue(){                                                                            //sendTempHumidValue() changes the value stored in charArray
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(100);
    return;
  }
  
  Serial.println("code point 1");delay(50);

  itoa(h, charArray, 10);
  strcat(charArray, ".");                   //append decimal point
  c = (h - (int)h) * 1000;//subtract to get the decimals, and multiply by 1000
  itoa(c, temp, 10);                  //convert to a second string
  strcat(charArray, temp);               //and append to the first

  Serial.println("code point 2");delay(50);
  
  sendValue(charArray);
  Serial.println("");
/*
  itoa(t, charArray, 10);
  strcat(charArray, ".");                   //append decimal point
  c = (t - (int)t) * 1000;      //subtract to get the decimals, and multiply by 1000
  itoa(c, temp, 10);                  //convert to a second string
  strcat(charArray, temp);               //and append to the first

  sendValue(charArray);
  Serial.println("");
  */
}

void sendSoilValue(){
  //Will improve the accuracy of the reading later.
  value = int (100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76);
  //Conforming to a range between 0 and 100.
  if (value < 0){value = 0;}
  if (value > 100){value = 100;}

  //Store value as a String charArray. 10 means decimal format.
  itoa(value, soilCharArray, 10);

  sendValue("12345.6789"); //Debug purpose only
  Serial.println("");delay(50);
  sendValue(soilCharArray);
  Serial.println("");
}

/**************************************************************/

/*Runs once at startup*/
void setup() {
  delay(20000);
  Serial.begin(9600);
  dht.begin(); //Start DHT sensor
}

/*Runs Continuously after the setup()*/
void loop() {
  sendSoilValue();
  sendTempHumidValue();   //sendTempHumidValue() changes the value stored in charArray
   
  delay(2000); //delay
}
