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
  // J1-1
  // J1-S-6
  digitalWrite(CPU_J1_A9, HIGH);
  digitalWrite(CPU_J1_A10, HIGH);
}
void Relay_short_2()
{
  // J1-6, J1-S-11
  digitalWrite(E_3, LOW);
  digitalWrite(E_0, LOW);
  // J1-6
  digitalWrite(CPU_J1_A3, HIGH);
  // J1-S-11
  digitalWrite(CPU_J1_A9, HIGH);
  digitalWrite(CPU_J1_A10, HIGH);
  digitalWrite(CPU_J1_A11, HIGH);
}
void Relay_short_3()
{
  // J1-11, J1-S-13
  digitalWrite(E_3, LOW);
  digitalWrite(E_0, LOW);
  // J1-11
  digitalWrite(CPU_J1_A2, HIGH);
  // J1-S-13
  digitalWrite(CPU_J1_A8, HIGH);
}
void Relay_short_4()
{
  // J1-13, J1-S-15
  digitalWrite(E_3, LOW);
  digitalWrite(E_0, LOW);
  // J1-13
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // J1-S-15
  digitalWrite(CPU_J1_A8, HIGH);
  digitalWrite(CPU_J1_A11, HIGH);
}
void Relay_short_5()
{
  // J1-15, J1-S-16
  digitalWrite(E_3, LOW);
  digitalWrite(E_0, LOW);
  // J1-15
  digitalWrite(CPU_J1_A1, HIGH);
  // J1-S-16
  digitalWrite(CPU_J1_A8, HIGH);
  digitalWrite(CPU_J1_A10, HIGH);
}
void Relay_short_6()
{
  // J1-16, J1-S-17
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
  // J1-16
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // J1-S-17

}
void Relay_short_7()
{
  // J1-17, J1-S-18
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
  // J1-17
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  // J1-S-18
  digitalWrite(CPU_J1_A15, HIGH);
}
void Relay_short_8()
{
  // J1-18, J1-S-19
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
  // J1-18
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // J1-S-19
  digitalWrite(CPU_J1_A14, HIGH);
}
void Relay_short_9()
{
  // J1-19, J1-S-20
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
  // J1-19
  digitalWrite(CPU_J1_A0, HIGH);
  // J1-S-20
  digitalWrite(CPU_J1_A14, HIGH);
  digitalWrite(CPU_J1_A15, HIGH);
}
void Relay_short_10()
{
  // J1-20, J1-S-21
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
  
}
void Relay_short_11()
{
  // J1-21, J1-S-22
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_12()
{
  // J1-22, J1-S-23
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_13()
{
  // J1-23, J1-S-24
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_14()
{
  // J1-24, J1-S-25
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_15()
{
  // J1-25, J1-S-26
  digitalWrite(E_4, LOW);
  digitalWrite(E_0, LOW);
}
void Relay_short_16()
{
  // J1-26, J1-S-27
  digitalWrite(E_4, LOW);
  digitalWrite(E_2, LOW);
}
void Relay_short_17()
{
  // J1-27, J1-S-28
  digitalWrite(E_4, LOW);
  digitalWrite(E_2, LOW);
}
void Relay_short_18()
{
  // J1-28, J1-S-29
  digitalWrite(E_4, LOW);
  digitalWrite(E_2, LOW);
}
void Relay_short_19()
{
  // J1-29, J1-S-30
  digitalWrite(E_4, LOW);
  digitalWrite(E_2, LOW);
}