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
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-1
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_2()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-2
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_3()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-21
  digitalWrite(27, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_4()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-22
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_5()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-4
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_6()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-5
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_7()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-8
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_8()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-9
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_9()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-13
  digitalWrite(26, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_10()
{
  digitalWrite(E_2, LOW);
  digitalWrite(E_1, LOW);
  // P207-14
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_11()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-15
  digitalWrite(15, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_12()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-18
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_13()
{
  digitalWrite(E_2, LOW);
  digitalWrite(60, LOW);
  // P207-23
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_14()
{
  digitalWrite(E_2, LOW);
  digitalWrite(60, LOW);
  // P207-24
  digitalWrite(39, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_15()
{
  digitalWrite(E_2, LOW);
  digitalWrite(60, LOW);
  // P207-25
  digitalWrite(40, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_16()
{
  digitalWrite(E_2, LOW);
  digitalWrite(60, LOW);
  // P207-26

  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_17()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-6
  digitalWrite(33, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_18()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-7
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_19()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-16
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}
void Relay_Capacitance_20()
{
  digitalWrite(E_2, LOW);
  digitalWrite(69, LOW);
  // P207-17
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  // chassis
  digitalWrite(38, HIGH);
}