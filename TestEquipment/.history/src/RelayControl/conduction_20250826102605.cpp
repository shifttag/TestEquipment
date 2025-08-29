#include "conduction.h"
#include "communication/common.h"

String controlRelayConduction(int conductionNum)
{
  if (conductionNum >= 1 && conductionNum <= 21)
  {

    relayConductions[conductionNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Realy_Conduction_1()
{
  // J1-1, P207-1
  reset();
}
void Realy_Conduction_2()
{
  // J1-6, P207-2
  digitalWrite(36, HIGH); // J1-6
  digitalWrite(28, HIGH); // P207-2
  reset();
}
void Realy_Conduction_3()
{
  // J1-11, P207-21
  digitalWrite(35, HIGH); // J1-11
  digitalWrite(27, HIGH); // P207-21
  reset();
}
void Realy_Conduction_4()
{
  // J1-13, P207-22
  // J1-13
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // P207-22
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_5()
{
  // J1-15, P207-13
  digitalWrite(34, HIGH); // J1-15
  digitalWrite(26, HIGH); // P207-13
  reset();
}
void Realy_Conduction_6()
{
  // J1-16, P207-4
  // J1-16
  digitalWrite(34, HIGH);
  digitalWrite(36, HIGH);
  // P207-4
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_7()
{
  // J1-17, P207-14
  // J1-17
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  // P207-14
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  reset();
}
void Realy_Conduction_8()
{
  // J1-18, P207-5
  // J1-18
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // P207-15
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_9()
{
  // J1-19, P207-15
  digitalWrite(33, HIGH); // J1-19
  digitalWrite(15, HIGH); // P207-15
  reset();
}
void Realy_Conduction_10()
{
  // J1-20, P207-6
  // J1-20
  digitalWrite(33, HIGH);
  digitalWrite(36, HIGH);
  // P207-6
  digitalWrite(15, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_11()
{
  // J1-21, P207-16
  // J1-21
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  // P207-16
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  reset();
}
void Realy_Conduction_12()
{
  // J1-22, P207-7
  // J1-22
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  // P207-7
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_13()
{
  // J1-23, P207-17
  // J1-23
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  // P207-17
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  reset();
}
void Realy_Conduction_14()
{
  // J1-24, P207-8
  // J1-24
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(36, HIGH);
  // P207-8
  digitalWrite(15, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  reset();
}
void Realy_Conduction_15()
{
  // J1-25, P207-18
  reset();
}
void Realy_Conduction_16()
{
  // J1-26, P207-9
  reset();
}
void Realy_Conduction_17()
{
  // J1-27, P207-26
  reset();
}
void Realy_Conduction_18()
{
  // J1-28, P207-25
  reset();
}
void Realy_Conduction_19()
{
  // J1-29, P207-24
  reset();
}
void Realy_Conduction_20()
{
  // J1-30, P207-23
  reset();
}
void Realy_Conduction_21()
{
  // J1-샤시, P207-19
  reset();
}
