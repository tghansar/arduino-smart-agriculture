//This sketch will be uploaded to the Yun. It will be able to test/monitor if there are activity of incoming packets over the XBee 802.15.4 unicast network

#include <SoftwareSerial.h>
//#include <Console.h>
#include <XBee.h>

XBee _xbee = XBee();
SoftwareSerial mySerial(8, 9); // RX, TX

void setup()
{
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);

  ////Serial.begin(9600);
  _xbee.begin(mySerial);
}

void loop()
{
  processXBeePackets();  
}

void processXBeePackets()
{
  _xbee.readPacket();

  if (_xbee.getResponse().isAvailable())
  {
    digitalWrite(13, HIGH);
    //Console.println("Data was received");
    delay(50);
  }
}
