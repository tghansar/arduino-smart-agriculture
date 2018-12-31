#include <FileIO.h>


/*This code will test if you can log data to the microSD card straight from the analog sensor*/

/*soilMoisture.ino start*/
const int soilMoistureAnalogPin = A0;   //Select the analog reading feature of the sensor and link it to the A0 pin.
int value = 0;
/*soilMoisture.ino end*/

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();

  while(!SerialUSB){;}
  SerialUSB.println("Filesystem datalogger started\n");
}

void loop() {

  if(counter>9){}//Do nothing after 10 iterations
  else
  {
    // put your main code here, to run repeatedly:
    String data = "";
  
    /*soilMoisture.ino start*/
    double value = 100.00-(analogRead(soilMoistureAnalogPin)*1.00-300)/3.76;
    Serial.println(value);
    delay(500); //Half a second delay between each reading
    /*soilMoisture.ino end*/
  
    data = String(value);
  
    //File IO
    File dataFile = FileSystem.open("/mnt/sda1/datalog.txt", FILE_APPEND);  //With the modifier FILE_APPEND, you can write information to the end of the file. If the file doesn't already exist, it will be created.
   
    if(dataFile)//Is true once file is successfuly opened or written
    {
      dataFile.println(data);
      dataFile.close();
      //alert, if you cannot see this then play with LED pin 13 for messages
      SerialUSB.println(data);// print to the serial port too
    }
    else
    {
      SerialUSB.println("error opening datalog.txt"); //Debug, rewrite code
    }
  
    counter = counter+1;
    delay(5000);
  }
}
