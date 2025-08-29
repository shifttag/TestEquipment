#include "common.h"

const int resetPins[] = {33, 34, 35, 36, 15, 26, 27, 28, 37, 38, 39, 40, 41, 92, 93, 51, };

void reset()
{
  for (int i = 0; i < sizeof(resetPins) / sizeof((resetPins[0])); i++)
  {
    digitalWrite(resetPins[i], LOW);
  }
}

