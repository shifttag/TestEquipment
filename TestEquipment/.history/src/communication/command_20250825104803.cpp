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
    String status = controlRelayConduction(num);
    // 처리 완료 후 명확히 전송
    if(status == "OK") {
      sendLED(getPattern(num));
      SerialUSB.print("RESULT: conduction");
      SerialUSB.print(num);
      SerialUSB.println("_OK");
    } 
    delay(2); // USB 안정화
    ledReset(); // LED 상태 초기화
  }
  else if (command.startsWith("short"))
  {
    int num = command.substring(5).toInt();
    String status = controlRelayShort(num);
    if (status == "OK") {
      sendLED(getPattern(num + 1));
      SerialUSB.print("RESULT: short");
      SerialUSB.print(num);
      SerialUSB.println("_OK");
    }
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
