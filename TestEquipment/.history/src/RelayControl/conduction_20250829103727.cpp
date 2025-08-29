#include "conduction.h"
#include "communication/common.h"

String controlRelayConduction(int conductionNum)
{
  if (conductionNum >= 1 && conductionNum <= 21)
  {
    reset();
    relayConductions[conductionNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Realy_Conduction_1()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-1, P207-1
}
void Realy_Conduction_2()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-6, P207-2
  digitalWrite(CPU_J1_A3, HIGH); // J1-6
  digitalWrite(28, HIGH); // P207-2
}
void Realy_Conduction_3()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-11, P207-21
  digitalWrite(CPU_J1_A2, HIGH); // J1-11
  digitalWrite(27, HIGH); // P207-21
}
void Realy_Conduction_4()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-13, P207-22
  // J1-13
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-22
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_5()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-15, P207-13
  digitalWrite(CPU_J1_A1, HIGH); // J1-15
  digitalWrite(26, HIGH); // P207-13
}
void Realy_Conduction_6()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-16, P207-4
  // J1-16
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-4
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_7()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-17, P207-14
  // J1-17
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  // P207-14
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
}
void Realy_Conduction_8()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-18, P207-5
  // J1-18
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-15
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_9()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-19, P207-15
  digitalWrite(CPU_J1_A0, HIGH); // J1-19
  digitalWrite(15, HIGH); // P207-15
}
void Realy_Conduction_10()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-20, P207-6
  // J1-20
  digitalWrite(CPU_J1_A0, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-6
  digitalWrite(15, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_11()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-21, P207-16
  // J1-21
  digitalWrite(CPU_J1_A0, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  // P207-16
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
}
void Realy_Conduction_12()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-22, P207-7
  // J1-22
  digitalWrite(CPU_J1_A0, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-7
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_13()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-23, P207-17
  // J1-23
  digitalWrite(CPU_J1_A0, HIGH);
  digitalWrite(CPU_J1_A1, HIGH);
  // P207-17
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
}
void Realy_Conduction_14()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-24, P207-8
  // J1-24
  digitalWrite(CPU_J1_A0, HIGH);
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-8
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_15()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-25, P207-18
  // J1-25
  digitalWrite(33, HIGH);
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  // P207-18
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
}
void Realy_Conduction_16()
{
  digitalWrite(E_1, LOW);
  digitalWrite(E_0, LOW);
  // J1-26, P207-9
  // J1-26
  digitalWrite(33, HIGH);
  digitalWrite(CPU_J1_A1, HIGH);
  digitalWrite(CPU_J1_A2, HIGH);
  digitalWrite(CPU_J1_A3, HIGH);
  // P207-9
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
}
void Realy_Conduction_17()
{
  digitalWrite(61, LOW);
  digitalWrite(60, LOW);
  // J1-27, P207-26
}
void Realy_Conduction_18()
{
  digitalWrite(61, LOW);
  digitalWrite(60, LOW);
  // J1-28, P207-25
  digitalWrite(40, HIGH); // J1-28
  digitalWrite(51, HIGH); // P207-25
}
void Realy_Conduction_19()
{
  digitalWrite(61, LOW);
  digitalWrite(60, LOW);
  // J1-29, P207-24
  digitalWrite(39, HIGH); // J1-29
  digitalWrite(93, HIGH); // P207-24
}
void Realy_Conduction_20()
{
  digitalWrite(61, LOW);
  digitalWrite(60, LOW);
  // J1-30, P207-23
  // J1-30
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  // P207-23
  digitalWrite(93, HIGH);
  digitalWrite(51, HIGH);
}
void Realy_Conduction_21()
{
  digitalWrite(61, LOW);
  digitalWrite(60, LOW);
  // J1-샤시, P207-19
  digitalWrite(38, HIGH); // J1-샤시
  digitalWrite(92, HIGH); // P207-19
}
