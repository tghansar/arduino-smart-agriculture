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
