#include "chassis.h"
#include "communication/common.h"

String controlRelayChassis(int chassisNum)
{
  if (chassisNum >= 1 && chassisNum <= 20)
  {
    relayChassis[chassisNum - 1](); // 배열 인덱스는 0부터 시작
    return "OK";
  }
  return "Invalid";
}

void Realy_Chassis_1()
{
  reset();
}
void Realy_Chassis_2()
{
  reset();
}
void Realy_Chassis_3()
{
  reset();
}
void Realy_Chassis_4()
{
  reset();
}
void Realy_Chassis_5()
{
  reset();
}
void Realy_Chassis_6()
{
  reset();
}
void Realy_Chassis_7()
{
  reset();
}
void Realy_Chassis_8()
{
  reset();
}
void Realy_Chassis_9()
{
  reset();
}
void Realy_Chassis_10()
{
  reset();
}
void Realy_Chassis_11()
{
  reset();
}
void Realy_Chassis_12()
{
  reset();
}
void Realy_Chassis_13()
{
  reset();
}
void Realy_Chassis_14()
{
  reset();
}
void Realy_Chassis_15()
{
  reset();
}
void Realy_Chassis_16()
{
  reset();
}
void Realy_Chassis_17()
{
  reset();
}
void Realy_Chassis_18()
{
  reset();
}
void Realy_Chassis_19()
{
  reset();
}
void Realy_Chassis_20()
{
  reset();
}
