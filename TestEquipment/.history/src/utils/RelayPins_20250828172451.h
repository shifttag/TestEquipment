#ifndef RelayPins_h
#define RelayPins_h

// ============== RELAY ==============
#define RX 0
#define TX 1
#define S_RST 18
#define S_RXD 17
#define S_TXD 16
#define T_LED1 73
#define MISO 74
#define MOSI 75
#define SPCK 76
#define CPU_DI_0 94
#define CPU_DI_1 95
#define CPU_DI_2 96
#define CPU_DI_3 97
#define UOTGID 85
#define PWM13 22
#define CPU_J1_A0 33
#define CPU_J1_A1 34
#define CPU_J1_A2 35
#define CPU_J1_A3 36
#define CPU_J1_A4 37
#define CPU_J1_A5 38
#define CPU_J1_A6 39
#define CPU_J1_A7 40
#define CPU_J1_A8 41
#define CPU_J1_A9 92
#define CPU_J1_A10 93
#define CPU_J1_A11 51
#define CPU_J1_A12 50
#define CPU_J1_A13 49
#define CPU_J1_A14 48
#define CPU_J1_A15 47
#define T_LED2 72
#define CPU_J207_A0 15
#define CPU_J207_A1 26
#define CPU_J207_A2 27
#define CPU_J207_A3 28
#define S_TXD3 14
#define S_RXD3 15
#define E_0 68
#define E_1 68
// 68/69 - CANRX0/CANTX0
{PIOA, PIO_PA1, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER},     // CANRX
    {PIOA, PIO_PA0, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER}, // CANTX

#endif