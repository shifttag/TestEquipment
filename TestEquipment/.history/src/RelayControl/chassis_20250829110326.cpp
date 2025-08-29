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
}
void Realy_Chassis_2()
{
  // chassis
}
void Realy_Chassis_3()
{
  // chassis
}
void Realy_Chassis_4()
{
  // chassis
}
void Realy_Chassis_5()
{
  // chassis
}
void Realy_Chassis_6()
{
  // chassis
}
void Realy_Chassis_7()
{
  // chassis
}
void Realy_Chassis_8()
{
  // chassis
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
}
void Realy_Chassis_18()
{
}
void Realy_Chassis_19()
{
}
void Realy_Chassis_20()
{
}
