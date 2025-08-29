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
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_2()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_3()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_4()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_5()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_6()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_7()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_8()
{
  // chassis
  digitalWrite(CPU_J1_A5, HIGH);
}
void Realy_Chassis_9()
{
  // chassis
}
void Realy_Chassis_10()
{
  // chassis
}
void Realy_Chassis_11()
{
  // chassis
}
void Realy_Chassis_12()
{
  // chassis
}
void Realy_Chassis_13()
{
  // chassis
}
void Realy_Chassis_14()
{
  // chassis
}
void Realy_Chassis_15()
{
  // chassis
}
void Realy_Chassis_16()
{
  // chassis
}
void Realy_Chassis_17()
{
  // chassis
}
void Realy_Chassis_18()
{
  // chassis
}
void Realy_Chassis_19()
{
  // chassis
}
void Realy_Chassis_20()
{
  // chassis
}
