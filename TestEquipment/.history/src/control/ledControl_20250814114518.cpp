#include "ledControl.h"

void sendLED(uint32_t data)
{
  for (int i = 24; i >= 0; i--)
  {
    digitalWrite(MOSI, (data >> i) & 0x01);
    digitalWrite(SPCK, HIGH);
    digitalWrite(SPCK, LOW);
  }
}

uint32_t getPattern(int ledNum)
{
  if (ledNum < 1 || ledNum > 24)
  {
    return 0;
  }
  return (uint32_t)1 << (24 - ledNum);
}

void ledReset()
{
  for (int i = 0; i < 24; i++)
  {
    digitalWrite(MOSI, LOW);
    digitalWrite(SPCK, HIGH);
    digitalWrite(SPCK, LOW);
  }
