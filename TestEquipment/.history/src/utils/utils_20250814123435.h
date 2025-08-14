#ifndef UTILS_H
#define UTILS_H
#include <Arduino.h>

using FuncPtr = void (*)(); // 함수 포인터 타입 정의

extern FuncPtr relayConductions[];
extern FuncPtr relayShorts[];
extern FuncPtr relayChassis[];
extern FuncPtr relayCapacitance[];

#endif