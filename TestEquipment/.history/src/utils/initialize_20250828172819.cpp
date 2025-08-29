#include "initialize.h"

void initialize()
{
  digitalWrite(CPU_DI_0, LOW);
  digitalWrite(CPU_DI_1, LOW);
  digitalWrite(CPU_DI_2, LOW);
  digitalWrite(CPU_DI_3, LOW);

  digitalWrite(CPU_J1_A0, LOW);
  digitalWrite(CPU_J1_A1, LOW);
  digitalWrite(CPU_J1_A2, LOW);
  digitalWrite(CPU_J1_A3, LOW);
  digitalWrite(CPU_J1_A4, LOW);
  digitalWrite(CPU_J1_A5, LOW);
  digitalWrite(CPU_J1_A6, LOW);
  digitalWrite(CPU_J1_A7, LOW);
  digitalWrite(CPU_J1_A8, LOW);
  digitalWrite(CPU_J1_A9, LOW);
  digitalWrite(CPU_J1_A10, LOW);
  digitalWrite(CPU_J1_A11, LOW);
  digitalWrite(CPU_J1_A12, LOW);
  digitalWrite(CPU_J1_A13, LOW);
  digitalWrite(CPU_J1_A14, LOW);
  digitalWrite(CPU_J1_A15, LOW);

  digitalWrite(CPU_J207_A0, LOW);
  digitalWrite(CPU_J207_A1, LOW);
  digitalWrite(CPU_J207_A2, LOW);
  digitalWrite(CPU_J207_A3, LOW);

  digitalWrite(T_LED1, LOW);
  digitalWrite(T_LED2, LOW);

  digitalWrite(MOSI, LOW);
  digitalWrite(SPCK, LOW);

  digitalWrite(E_0, LOW);
}