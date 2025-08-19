#include "configuration.h"

void configuration()
{
  SerialUSB.println("1");
  pinMode(CPU_DI_0, OUTPUT);
  pinMode(CPU_DI_1, OUTPUT);
  pinMode(CPU_DI_2, OUTPUT);
  pinMode(CPU_DI_3, OUTPUT);
  SerialUSB.println("2");
  pinMode(CPU_J1_A0, OUTPUT);
  pinMode(CPU_J1_A1, OUTPUT);
  pinMode(CPU_J1_A2, OUTPUT);
  pinMode(CPU_J1_A3, OUTPUT);
  pinMode(CPU_J1_A4, OUTPUT);
  pinMode(CPU_J1_A5, OUTPUT);
  pinMode(CPU_J1_A6, OUTPUT);
  pinMode(CPU_J1_A7, OUTPUT);
  pinMode(CPU_J1_A8, OUTPUT);
  pinMode(CPU_J1_A9, OUTPUT);
  pinMode(CPU_J1_A10, OUTPUT);
  pinMode(CPU_J1_A11, OUTPUT);
  pinMode(CPU_J1_A12, OUTPUT);
  pinMode(CPU_J1_A13, OUTPUT);
  pinMode(CPU_J1_A14, OUTPUT);
  pinMode(CPU_J1_A15, OUTPUT);
  SerialUSB.println("3");
  pinMode(CPU_J207_A0, OUTPUT);
  pinMode(CPU_J207_A1, OUTPUT);
  pinMode(CPU_J207_A2, OUTPUT);
  pinMode(CPU_J207_A3, OUTPUT);
  SerialUSB.println("4");
  pinMode(T_LED1, OUTPUT);
  pinMode(T_LED2, OUTPUT);
  SerialUSB.println("5");
  pinMode(MOSI, OUTPUT);
  pinMode(SPCK, OUTPUT);
}