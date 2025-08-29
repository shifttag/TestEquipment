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
}
void Realy_Chassis_2()
{
}
void Realy_Chassis_3()
{
}
void Realy_Chassis_4()
{
}
void Realy_Chassis_5()
{
}
void Realy_Chassis_6()
{
}
void Realy_Chassis_7()
{
}
void Realy_Chassis_8()
{
}
void Realy_Chassis_9()
{
}
void Realy_Chassis_10()
{
}
void Realy_Chassis_11()
{
}
void Realy_Chassis_12()
{
}
void Realy_Chassis_13()
{
}
void Realy_Chassis_14()
{
}
void Realy_Chassis_15()
{
}
void Realy_Chassis_16()
{
}
void Realy_Chassis_17()
{
}
void Realy_Chassis_18()
{
}
void Realy_Chassis_19()
{
  reset();
}
void Realy_Chassis_20()
{
  reset();
}
