#include "common.h"

const int resetPins[] = {CPU_J1_A0, CPU_J1_A1, CPU_J1_A2, CPU_J1_A3, CPU_J207_A0, CPU_J207_A1, 
  CPU_J207_A2, CPU_J207_A3, CPU_J1_A4, CPU_J1_A5, CPU_J1_A6, CPU_J1_A7, CPU_J1_A8, CPU_J1_A9, 
  CPU_J1_A10, CPU_J1_A11, CPU_J1_A12, CPU_J1_A13, CPU_J1_A14, CPU_J1_A15};
const int resetRegister[] = {E_0, 60, 61, 68, 69};

void reset()
{
  for (int i = 0; i < sizeof(resetPins) / sizeof((resetPins[0])); i++)
  {
    digitalWrite(resetPins[i], LOW);
  }
  for (int i = 0; i < sizeof(resetRegister) / sizeof(resetRegister[0]); i++)
  {
    digitalWrite(resetRegister[i], HIGH);
  }
}
