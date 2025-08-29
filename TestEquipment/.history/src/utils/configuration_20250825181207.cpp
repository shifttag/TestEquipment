#include "configuration.h"

void configuration()
{
  // 입력핀으로 사용되는 CPU 관련 핀들
  pinMode(S_DIN_01, OUTPUT);
  pinMode(S_DIN_02, OUTPUT);
  pinMode(S_DIN_03, OUTPUT);
  pinMode(S_DIN_04, OUTPUT);
  pinMode(S_DIN_05, OUTPUT);
  pinMode(S_DIN_06, OUTPUT);
  pinMode(S_DIN_07, OUTPUT);
  pinMode(S_DIN_08, OUTPUT);
  pinMode(S_DIN_09, OUTPUT);
  pinMode(S_DIN_10, OUTPUT);
  pinMode(S_DIN_11, OUTPUT);
  pinMode(S_DIN_12, OUTPUT);
  pinMode(S_DIN_13, OUTPUT);
  pinMode(S_DIN_14, OUTPUT);
  pinMode(S_DIN_15, OUTPUT);
  pinMode(S_DIN_16, OUTPUT);
  pinMode(S_DIN_17, OUTPUT);
  pinMode(S_DIN_18, OUTPUT);
  pinMode(S_DIN_19, OUTPUT);
  pinMode(S_DIN_20, OUTPUT);
  pinMode(S_DIN_21, OUTPUT);
  pinMode(S_DIN_22, OUTPUT);
  pinMode(S_DIN_23, OUTPUT);
  pinMode(S_DIN_24, OUTPUT);
  pinMode(S_DIN_25, OUTPUT);
  pinMode(S_DIN_26, OUTPUT);
  pinMode(S_DIN_27, OUTPUT);
  pinMode(S_DIN_28, OUTPUT);
  pinMode(S_DIN_29, OUTPUT);
  pinMode(S_DIN_30, OUTPUT);
  pinMode(S_DIN_31, OUTPUT);
  pinMode(S_DIN_32, OUTPUT);

  // 출력 핀들
  pinMode(S_DOUT_01, OUTPUT);
  pinMode(S_DOUT_02, OUTPUT);
  pinMode(S_DOUT_03, OUTPUT);
  pinMode(S_DOUT_04, OUTPUT);
  pinMode(S_DOUT_05, OUTPUT);
  pinMode(S_DOUT_06, OUTPUT);
  pinMode(S_DOUT_07, OUTPUT);
  pinMode(S_DOUT_08, OUTPUT);
  pinMode(S_DOUT_09, OUTPUT);
  pinMode(S_DOUT_10, OUTPUT);
  pinMode(S_DOUT_11, OUTPUT);
  pinMode(S_DOUT_12, OUTPUT);
  pinMode(S_DOUT_13, OUTPUT);
  pinMode(S_DOUT_14, OUTPUT);
  pinMode(S_DOUT_15, OUTPUT);
  pinMode(S_DOUT_16, OUTPUT);
  pinMode(S_DOUT_17, OUTPUT);
  pinMode(S_DOUT_18, OUTPUT);
  pinMode(S_DOUT_19, OUTPUT);
  pinMode(S_DOUT_20, OUTPUT);
  pinMode(S_DOUT_21, OUTPUT);
  pinMode(S_DOUT_22, OUTPUT);
  pinMode(S_DOUT_23, OUTPUT);
  pinMode(S_DOUT_24, OUTPUT);

  // SPI 및 기타 핀
  pinMode(T_LED1, OUTPUT);
  pinMode(T_LED2, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SPCK, OUTPUT);

  // 인코더 관련 핀
  pinMode(ENC_RX1, OUTPUT);
  pinMode(ENC_RX2, OUTPUT);
  pinMode(ENC_TX1, OUTPUT);
  pinMode(ENC_TX2, OUTPUT);

  // 홀센서 관련 핀
  pinMode(S_HALL_A, OUTPUT);
  pinMode(S_HALL_B, OUTPUT);
  pinMode(S_HALL_C, OUTPUT);

  // UART 및 시스템 관련 핀
  pinMode(RX, OUTPUT);
  pinMode(TX, OUTPUT);
  pinMode(S_RST, OUTPUT);
  pinMode(S_RXD, OUTPUT);
  pinMode(S_TXD, OUTPUT);

  // PWM 핀
  pinMode(PWM13, OUTPUT);

}
