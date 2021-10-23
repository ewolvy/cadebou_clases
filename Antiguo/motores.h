#ifndef motores_h

#define motores_h

#include <Arduino.h>
#include "setup.h"
#include <ESP32Encoder.h>

typedef struct PinesMotores{
  uint8_t adelante, atras;
  uint8_t canal_adelante, canal_atras;
}PinesMotores;

void mover_motor(PinesMotores pines, int speed);
void motor_full_stop(PinesMotores izq, PinesMotores dch);
void avanza(PinesMotores izq, PinesMotores dch, ESP32Encoder myEncoderLeft, ESP32Encoder myEncoderRight, uint8_t casillas);

#endif
