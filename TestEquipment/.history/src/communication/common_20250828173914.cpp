#include "common.h"

const int resetPins[] = {33, 34, 35, 36, 15, 26, 27, 28, 37, 38, 39, 40, 41, 92, 93, 51};
const int resetRegister[] = {59, 60, 61, 68, 69};

void reset()
{
  for (int i = 0; i < sizeof(resetPins) / sizeof((resetPins[0])); i++)
  {
    digitalWrite(resetPins[i], LOW);
  }
  for (int i = 0; i < sizeof(resetRegister) / sizeof(resetRegister[0]); i++) {
  digitalWrite()}
}

#define E_0 68
#define E_1 69
#define E_2 61
#define E_3 60
#define E_4 59