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
}
void Relay_short_2()
{
}
void Relay_short_3()
{
}
void Relay_short_4()
{
}
void Relay_short_5()
{
}
void Relay_short_6()
{
}
void Relay_short_7()
{
}
void Relay_short_8()
{
}
void Relay_short_9()
{
  reset();
}
void Relay_short_10()
{
  reset();
}
void Relay_short_11()
{
  reset();
}
void Relay_short_12()
{
  reset();
}
void Relay_short_13()
{
  reset();
}
void Relay_short_14()
{
  reset();
}
void Relay_short_15()
{
  reset();
}
void Relay_short_16()
{
  reset();
}
void Relay_short_17()
{
  reset();
}
void Relay_short_18()
{
  reset();
}
void Relay_short_19()
{
  reset();
}