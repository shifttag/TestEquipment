#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "Arduino.h"
#include "utils/RelayPins.h"

void sendLED(uint32_t data);
void ledReset();
uint32_t getPattern(int ledNum);
uint32_t getModePattern(int mode);

void conductionModeLedControl(int num);
void shortModeLedControl(int num);
void chassisModeLedControl(int num);
void capacitanceLedControl

#endif