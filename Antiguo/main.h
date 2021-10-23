#ifndef main_h

#define main_h

#include <Arduino.h>
#include <Wire.h>
#include "setup.h"
#include "tft.h"
// #include "encoder.h"
#include <ESP32Encoder.h>
#include "motores.h"

void setupEncoders();
void setupMotores();
void doEncoderLeft();
void doEncoderRight();

#endif