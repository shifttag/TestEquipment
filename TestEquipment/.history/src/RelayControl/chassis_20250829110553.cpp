#include "chassis.h"
#include "communication/common.h"

String controlRelayChassis(int chassisNum)
{
  if (chassisNum >= 1 && chassisNum <= 20)
  {
    reset();
    relayChassis[chassisNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Realy_Chassis_1()
{
  digitalWrite(E_3, LOW);
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_2()
{
  digitalWrite(E_3, LOW);
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_3()
{
  digitalWrite(E_3, LOW);
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_4()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_5()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_6()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_7()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_8()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_9()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_10()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_11()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_12()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_13()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_14()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_15()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_16()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_17()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_18()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_19()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_20()
{
  digitalWrite(E_2, LOW);
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
