#include "capacitance.h"
#include "communication/common.h"

String controlRelayCapacitance(int capacitanceNum)
{
  if (capacitanceNum >= 1 && capacitanceNum <= 20)
  {
    relayCapacitance[capacitanceNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Relay_Capacitance_1()
{
}
void Relay_Capacitance_2()
{
  reset();
}
void Relay_Capacitance_3()
{
  reset();
}
void Relay_Capacitance_4()
{
  reset();
}
void Relay_Capacitance_5()
{
  reset();
}
void Relay_Capacitance_6()
{
  reset();
}
void Relay_Capacitance_7()
{
  reset();
}
void Relay_Capacitance_8()
{
  reset();
}
void Relay_Capacitance_9()
{
  reset();
}
void Relay_Capacitance_10()
{
  reset();
}
void Relay_Capacitance_11()
{
  reset();
}
void Relay_Capacitance_12()
{
  reset();
}
void Relay_Capacitance_13()
{
  reset();
}
void Relay_Capacitance_14()
{
  reset();
}
void Relay_Capacitance_15()
{
  reset();
}
void Relay_Capacitance_16()
{
  reset();
}
void Relay_Capacitance_17()
{
  reset();
}
void Relay_Capacitance_18()
{
  reset();
}
void Relay_Capacitance_19()
{
  reset();
}
void Relay_Capacitance_20()
{
  reset();
}