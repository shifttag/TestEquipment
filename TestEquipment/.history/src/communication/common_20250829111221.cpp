#include "common.h"

const int resetPins[] = {CPU_J1_A0, CPU_J1_A1, CPU_J1_A2, CPU_J1_A3, CPU_J207_A0, CPU_J207_A1, CPU_J207_A2, 28, 37, 38, 39, 40, 41, 92, 93, 51};
const int resetRegister[] = {59, 60, 61, 68, 69};

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
