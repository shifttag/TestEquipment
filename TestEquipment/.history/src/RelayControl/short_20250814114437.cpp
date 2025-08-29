#include "short.h"
#include "communication/common.h"

String controlRelayShort(int shortNum)
{
  if (shortNum >= 1 && shortNum <= 19)
  {

    relayShorts[shortNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Relay_short_1()
{
  reset();
}
void Relay_short_2()
{
  reset();
}
void Relay_short_3()
{
  reset();
}
void Relay_short_4()
{
  reset();
}
void Relay_short_5()
{
  reset();
}
void Relay_short_6()
{
  reset();
}
void Relay_short_7()
{
  reset();
}
void Relay_short_8()
{
  reset();
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