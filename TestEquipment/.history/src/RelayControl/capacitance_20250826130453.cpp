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
}
void Relay_Capacitance_8()
{
}
void Relay_Capacitance_9()
{
}
void Relay_Capacitance_10()
{
}
void Relay_Capacitance_11()
{
}
void Relay_Capacitance_12()
{
}
void Relay_Capacitance_13()
{
}
void Relay_Capacitance_14()
{
}
void Relay_Capacitance_15()
{
}
void Relay_Capacitance_16()
{
}
void Relay_Capacitance_17()
{
}
void Relay_Capacitance_18()
{
}
void Relay_Capacitance_19()
{
}
void Relay_Capacitance_20()
{
}