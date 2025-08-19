#include <Arduino.h>
#include "communication/command.h"
#include "utils/initialize.h"
#include "utils/configuration.h"
#include "control/ledControl.h"

void setup()
{
  SerialUSB.begin(115200);
  delay(3000);
  SerialUSB.println("DEBUG: USB ready");
  configuration();
  SerialUSB.println("DEBUG: Configuration done");
  initialize();
  SerialUSB.println("DEBUG: Initialization done");
}

void loop()
{
  SerialUSB.println("RESULT: Looping...");
  if(SerialUSB.available()) {
    cmd.readCommand();
  }
}


