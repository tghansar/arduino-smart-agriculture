/*Author: Taariq Ghansar
//Soil Moisture, Temp and Humidity
//Strictly always conform to 3.3V for both sensors!
//Always have atleast 2000 milliseconds difference between each temp and humidity sensing in the loop
*/
#include <stdlib.h>     //itoa()
#include "DHT.h"      //Temp and Humidity Sensor library from Adafruit

#define DHTPIN 2     // The digital pin for the Temp and Humidity sensor (Digital pin D2)
#define DHTTYPE DHT21   // The type of Sensor: DHT21 (AM2301)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor, not started yet.

const int soilMoistureAnalogPin = A0;   //Select the analog read to the A0 pin.


/***********************Functions used within the loop() procedure***********************************/
/*Help send string/char[] values one character at a time, works perfect for any text*/
void sendValue(char* chars){
  int lenOfText = strlen(chars);
  int i;
  for(i=0; i<lenOfText; i++ ){
    Serial.print(char(chars[i]));
    delay(50);
  }  
}

/*Grab soil moisture value and calculate an appropriate value; Converts 0-3300 mV to a percentage*/
void sendSoilValue(){
  //Will improve the accuracy of the reading later.
  int value = int (100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76);
  //Conforming to a range between 0 and 100.
  if (value < 0){value = 0;}
  if (value > 100){value = 100;}

  char soilMoistureValue[5];
  itoa(value, soilMoistureValue, 10);

  sendValue(soilMoistureValue);
}

/*Use the library from Adafruit to retrieve humidity and temperature values from the DH21 Sensor*/
void sendTempHumidValue(){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = (int)(dht.readHumidity());                                              //Losing precision of the float
  // Read temperature as Celsius (the default)
  int t = (int)(dht.readTemperature());                                           //Losing precision of the float

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(100);
    return;
  }

  char humidityValue[5];
  char temperatureValue[5];
  itoa(h, humidityValue, 10);
  itoa(t, temperatureValue, 10);
  
  sendValue(humidityValue);
  Serial.print(",");delay(50);
  Serial.print(" ");delay(50);
  sendValue(temperatureValue);
  Serial.print(",");delay(50);
  Serial.print(" ");delay(50);  
}
/*******************************************************************************************/


/*Runs once at startup*/
void setup() {
  Serial.begin(9600);//Start the default Serial
  dht.begin(); //Start DHT sensor
}

/*Runs Continuously after the setup()*/
void loop() {
  delay(2000);
  sendTempHumidValue();   //sendTempHumidValue() changes the value stored in charArray
  sendSoilValue();
  Serial.println("");
}
