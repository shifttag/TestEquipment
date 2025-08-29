#include "short.h"
#include "communication/common.h"

String controlRelayShort(int shortNum)
{
  if (shortNum >= 1 && shortNum <= 19)
  {
    reset();
    relayShorts[shortNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Relay_short_1()
{
  // J1-1, J1-S-6
  digitalWrite(E_3, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_2()
{
  // J1-6, J1-S-11
}
void Relay_short_3()
{
  // J1-11, J1-S-13
}
void Relay_short_4()
{
  // J1-13, J1-S-15
}
void Relay_short_5()
{
  // J1-15, J1-S-16
}
void Relay_short_6()
{
  // J1-16, J1-S-17
}
void Relay_short_7()
{
  // J1-17, J1-S-18
}
void Relay_short_8()
{
  // J1-18, J1-S-19
}
void Relay_short_9()
{
}
void Relay_short_10()
{
  // J1-1, J1-S-1
}
void Relay_short_11()
{
  // J1-1, J1-S-1
}
void Relay_short_12()
{
  // J1-1, J1-S-1
}
void Relay_short_13()
{
  // J1-1, J1-S-1
}
void Relay_short_14()
{
  // J1-1, J1-S-1
}
void Relay_short_15()
{
  // J1-1, J1-S-1
}
void Relay_short_16()
{
  // J1-1, J1-S-1
}
void Relay_short_17()
{
  // J1-1, J1-S-1
}
void Relay_short_18()
{
  // J1-1, J1-S-1
}
void Relay_short_19()
{
  // J1-1, J1-S-1
}