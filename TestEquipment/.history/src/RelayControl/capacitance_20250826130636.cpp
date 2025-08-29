#include "capacitance.h"
#include "communication/common.h"

String controlRelayCapacitance(int capacitanceNum)
{
  if (capacitanceNum >= 1 && capacitanceNum <= 20)
  {
    reset();
    relayCapacitance[capacitanceNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Relay_Capacitance_1()
{
  // P207-1

  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_2()
{
  
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_3()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_4()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_5()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_6()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_7()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_8()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_9()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_10()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_11()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_12()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_13()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_14()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_15()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_16()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_17()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_18()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_19()
{
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_20()
{
  // chassis
  digitalWrite(93, HIGH);
}