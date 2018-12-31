//Attempt: Read analog soil moisture data and print to console : Success using serial monitor or ssh root@10.0.0.100 'telnet localhost 6571'

#include <Console.h>

const int soilMoistureAnalogPin = A0;   //Select the analog reading feature of the sensor and link it to the A0 pin.
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Console.begin();
  while(!Console){;}
}

void loop() {
  // put your main code here, to run repeatedly:
  double value = 100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76;
  Console.println(value);
  delay(50);
  Console.flush();
  
  delay(500); //Half a second delay between each reading

}

/*
const int soilMoistureAnalogPin = A0;   //Select the analog reading feature of the sensor and link it to the A0 pin.
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double value = 100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76;
  Serial.println(value);
  delay(500); //Half a second delay between each reading
}
*/
