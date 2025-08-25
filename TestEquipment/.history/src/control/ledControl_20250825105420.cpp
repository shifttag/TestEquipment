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

uint32_t getModePattern(int mode)
{
}

void ledAllReset()
{
  uint32_t 
}

void conductionModeLedControl(int num)
{
  if(num == 1) {
    sendLED(getPattern(21));
  } else if(num == 21) {
    ledAllReset();
  }
}
