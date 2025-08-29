#include <Arduino.h>
#include "communication/command.h"
#include "utils/initialize.h"

void setup()
{
  SerialUSB.begin(115200);
  while(!SerialUSB) {
  }
  configuration();
  initialize();
}

void loop()
{
  SerialUSB.println("TEST");
  if(SerialUSB.available()) {
    cmd.readCommand();
  }
}


