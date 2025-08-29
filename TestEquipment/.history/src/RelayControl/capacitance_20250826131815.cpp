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
  // P207-2
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_3()
{
  // P207-21
  digitalWrite(35, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_4()
{
  // P207-22
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_5()
{
  // P207-4
  digitalWrite(34, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_6()
{
  // P207-5
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_7()
{
  // P207-8
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_8()
{
  // P207-9
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_9()
{
  // P207-13
  digitalWrite(34, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_10()
{
  // P207-14
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_11()
{
  // P207-15
  digitalWrite(33, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_12()
{
  // P207-18
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_13()
{
  // P207-23
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_14()
{
  // P207-24
  digitalWrite(39, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_15()
{
  // P207-25
  digitalWrite(40, HIGH);
  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_16()
{
  // P207-26

  // chassis
  digitalWrite(93, HIGH);
}
void Relay_Capacitance_17()
{
  // P207-6
  digitalWrite(33, HIGH);
  digitalWrite(36, HIGH);
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