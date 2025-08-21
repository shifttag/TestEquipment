#include <Arduino.h>
#include "communication/command.h"
#include "utils/initialize.h"
#include "utils/configuration.h"
#include "control/ledControl.h"

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


