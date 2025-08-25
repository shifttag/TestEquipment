#include "command.h"
#include "RelayControl/conduction.h"
#include "RelayControl/short.h"
#include "RelayControl/chassis.h"
#include "RelayControl/capacitance.h"
#include "control/ledControl.h"

Command cmd;
String inputBuffer = "";

void Command::readCommand()
{
  // Serial에 데이터가 있으면
  while (SerialUSB.available())
  {
    char c = SerialUSB.read();
    if (c == '\r' || c == '\n')
    {
      inputBuffer.trim();
      if (inputBuffer.length() > 0)
      {
        processCommand(inputBuffer);
      }
      inputBuffer = ""; // 처리 후 버퍼 초기화
    }
    else
    {
      inputBuffer += c;
    }
  }
}

void Command::processCommand(String command)
{
  if (command.startsWith("conduction"))
  {
    int num = command.substring(10).toInt();
    sendLED(getPattern(num));
    String status = controlRelayConduction(num);
    // 처리 완료 후 명확히 전송
    SerialUSB.print("RESULT: conduction");
    SerialUSB.print(num);
    SerialUSB.println("_OK");
    delay(2); // USB 안정화
    ledReset(); // LED 상태 초기화
  }
  else if (command.startsWith("short"))
  {
    int num = command.substring(5).toInt();
    sendLED(getPattern(num+1));
    String status = controlRelayShort(num);
    SerialUSB.print("RESULT: short");
    SerialUSB.print(num);
    SerialUSB.println("_OK");
    delay(2);
    ledReset(); // LED 상태 초기화
  }
  else if (command.startsWith("chassis"))
  {
    int num = command.substring(7).toInt();
    sendLED(getPattern(num));
    String status = controlRelayChassis(num);
    SerialUSB.print("RESULT: chassis");
    SerialUSB.print(num);
    SerialUSB.println("_OK");
    delay(2);
    ledReset(); // LED 상태 초기화
  }
  else if (command.startsWith("capacitance"))
  {
    int num = command.substring(11).toInt();
    sendLED(getPattern(num));
    String status = controlRelayCapacitance(num);
    SerialUSB.print("RESULT: capacitance");
    SerialUSB.print(num);
    SerialUSB.println("_OK");
    delay(2);
  }
  else
  {
    SerialUSB.println("RESULT: unknown_command");
    delay(2);
  }
}

// #include "command.h"
// #include "RelayControl/conduction.h"
// #include "RelayControl/short.h"
// #include "RelayControl/chassis.h"
// #include "RelayControl/capacitance.h"
// #include "control/ledControl.h"

// Command cmd;

// void Command::readCommand()
// {
//   if (SerialUSB.available())
//   {
//     SerialUSB.setTimeout(2000);
//     cmd.command = SerialUSB.readStringUntil('\n');
//     cmd.command.trim();

//     if (cmd.command.startsWith("conduction"))
//     {
//       int conductionNum = cmd.command.substring(10).toInt();

//       // LED Control
//       sendLED(getPattern(conductionNum));

//       // 릴레이 컨트롤
//       if (controlRelayConduction(conductionNum) == "OK")
//       {
//         SerialUSB.print("conduction");
//         SerialUSB.print(conductionNum);
//         SerialUSB.println("_OK");
//       }
//       else
//       {
//         SerialUSB.println("Invalid conduction number");
//       }
//     }

//     else if (cmd.command.startsWith("short"))
//     {
//       int shortNum = cmd.command.substring(5).toInt();

//       // LED Control
//       sendLED(getPattern(shortNum));

//       // 릴레이 컨트롤
//       if (controlRelayShort(shortNum) == "OK")
//       {
//         SerialUSB.print("short");
//         SerialUSB.print(shortNum);
//         SerialUSB.println("_OK");
//       }
//     }

//     else if (cmd.command.startsWith("chassis"))
//     {
//       int chassisNum = cmd.command.substring(7).toInt();

//       // LED Control
//       sendLED(getPattern(chassisNum));

//       // 릴레이 컨트롤
//       if (controlRelayChassis(chassisNum) == "OK")
//       {
//         SerialUSB.print("chassis");
//         SerialUSB.print(chassisNum);
//         SerialUSB.println("_OK");
//       }
//     }

//     else if (cmd.command.startsWith("capacitance"))
//     {
//       int capacitanceNum = cmd.command.substring(11).toInt();

//       // LED Control
//       sendLED(getPattern(capacitanceNum));

//       // 릴레이 컨트롤
//       if (controlRelayCapacitance(capacitanceNum) == "OK")
//       {
//         SerialUSB.print("capacitance");
//         SerialUSB.print(capacitanceNum);
//         SerialUSB.println("_OK");
//       }
//     }
//   }
// }
