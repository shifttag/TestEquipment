#include <Arduino.h>
#include "communication/command.h"
#include "utils/initialize.h"
#include "utils/configuration.h"
#include "control/ledControl.h"

Command cmd;

void setup()
{
  SerialUSB.begin(115200);
  configuration();
  initialize();
}

void loop()
{
  cmd.readCommand();
}
