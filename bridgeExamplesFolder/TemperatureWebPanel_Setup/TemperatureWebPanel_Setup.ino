#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 

// Listen on default port 5555, the webserver on the Yun
// will forward there all the HTTP requests for us.
YunServer server;
String startString;
long hits = 0;

void setup() {
  Serial.begin(9600);

  // Bridge startup
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  // using A0 and A2 as vcc and gnd for the TMP36 sensor:
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);

  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  server.listenOnLocalhost();
  server.begin();

  // get the time that this sketch started:
  Process startTime;
  startTime.runShellCommand("date");
  while(startTime.available()) {
    char c = startTime.read();
    startString += c;
  }
}

void loop(){}
