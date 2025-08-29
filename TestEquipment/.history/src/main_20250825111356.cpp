#include <Arduino.h>
#include "communication/command.h"
#include "utils/initialize.h"
#incldue "utils/"

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
  if(SerialUSB.available()) {
    cmd.readCommand();
  }
}


