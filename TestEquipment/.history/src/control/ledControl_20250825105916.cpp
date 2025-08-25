#include "ledControl.h"

uint32_t ledState = 0;

void sendLED(uint32_t data)
{
  ledState = data;
  for (int i = 23; i >= 0; i--)
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
  uint32_t mask = 0b111;
  uint32_t newState = ledState & mask;
  sendLED(newState);
}

void conductionModeLedControl(int num)
{
  if(num == 1) {
    sendLED(getPattern(22));
  } else if(num == 21) {
    sendLED(0);
  } 
}

void shortModeLedControl(int num)
{
  if (num == 1)
  {
    sendLED(getPattern(23));
  }
  else if (num == 19)
  {
    sendLED(0);
  }
}

void chassisModeLedControl(int num)
{
  if (num == 1)
  {
    sendLED(getPattern(24));
  }
  else if (num == 20)
  {
    sendLED(0);
  }
}

void capacitanceModeLedControl(int num)
{
  if (num == 1)
  {
    uint_
    sendLED(getPattern(23));
  }
  else if (num == 20)
  {
    sendLED(0);
  }
}
