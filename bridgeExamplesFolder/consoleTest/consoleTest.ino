/*Author: Taariq Ghansar*/

//Read more on: https://www.arduino.cc/en/Reference/YunConsoleConstructor
//Read example: ConsoleAsciiTable.ino in the examples folder for further understanding of more function calls
//See console_man.ino too

#include <Console.h>//This is the base class of Bridge class. Data can be seen on the serial monitor in the same manner as the serial on the Arduino Uno.

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Console.begin();

  while (!Console) {
    ; // wait for Console port to connect.
  }

  // prints title with ending line break
  Console.println("The console is working");
  delay(100);
  Console.println("The console is working and confirmed once again");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (counter < 20 ){                             //&& Console.connected()
    Console.println(counter);
    counter = counter + 1;
    delay(1000);
  }
  else{
    Console.flush();
    Console.end();
    }
}
