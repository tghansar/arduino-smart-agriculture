//Soil Moisture

#include <string.h>
#include <stdlib.h>

int value = 0;
char charArray[] = "";
int i;
int lenOfText;

const int soilMoistureAnalogPin = A0;   //Select the analog reading feature of the sensor and link it to the A0 pin.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = int (100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76);
  if (value < 0){value = 0;}                                                    //Will improve the accuracy of the reading later. Limiting range for now.
  if (value > 100){value = 100;}
  itoa(value, charArray, 10);

  int lenOfText = strlen(charArray);
  for(i=0; i<lenOfText; i++ ){
    Serial.print(char(charArray[i]));
    delay(50);
  }
  Serial.println("");


  
  //Serial.println(value);
  delay(450); //Half a second delay between each reading
}
