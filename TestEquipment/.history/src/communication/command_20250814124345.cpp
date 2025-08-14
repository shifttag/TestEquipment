#include "command.h"
#include "RelayControl/conduction.h"
#include "RelayControl/short.h"
#include "RelayControl/chassis.h"
#include "RelayControl/capacitance.h"
#include "control/ledControl.h"

Command cmd;

void Command::readCommand()
{
  if (SerialUSB.available())
  {
    cmd.command = SerialUSB.readStringUntil('\n');
    cmd.command.trim();

    if (cmd.command.startsWith("conduction"))
    {
      ledReset();
      String numStr = cmd.command.substring(10);
      int conductionNum = numStr.toInt();

      // LED Control
      uint32_t ledPattern = getPattern(conductionNum);
      sendLED(ledPattern);

      // 릴레이 컨트롤
      String result_conduction = controlRelayConduction(conductionNum);
      if (result_conduction == "OK")
      {
        SerialUSB.print("conduction");
        SerialUSB.print(conductionNum);
        SerialUSB.println("_OK");
      }
      else
      {
        SerialUSB.println("Invalid conduction number");
      }
    }

    else if (cmd.command.startsWith("short"))
    {
      ledReset();
      String numStr = cmd.command.substring(5);
      int shortNum = numStr.toInt();

      // LED Control
      uint32_t ledPattern = getPattern(shortNum);
      sendLED(ledPattern);

      // 릴레이 컨트롤
      String result_short = controlRelayShort(shortNum);
      if (result_short == "OK")
      {
        SerialUSB.print("short");
        SerialUSB.print(shortNum);
        SerialUSB.println("_OK");
      }
    }

    else if (cmd.command.startsWith("chassis"))
    {
      String numStr = cmd.command.substring(7);
      int chassisNum = numStr.toInt();

      // LED Control
      uint32_t ledPattern = getPattern(chassisNum);
      sendLED(ledPattern);

      // 릴레이 컨트롤
      String result_chassis = controlRelayChassis(chassisNum);
      if (result_chassis == "OK")
      {
        SerialUSB.print("chassis");
        SerialUSB.print(chassisNum);
        SerialUSB.println("_OK");
      }
    }

    else if (cmd.command.startsWith("capacitance"))
    {
      String numStr = cmd.command.substring(11);
      int capacitanceNum = numStr.toInt();

      // LED Control
      uint32_t ledPattern = getPattern(capacitanceNum);
      sendLED(ledPattern);

      // 릴레이 컨트롤
      String result_capacitance = controlRelayCapacitance(capacitanceNum);
      if (result_capacitance == "OK")
      {
        SerialUSB.print("capacitance");
        SerialUSB.print(capacitanceNum);
        SerialUSB.println("_OK");
      }
    }
  }
}
