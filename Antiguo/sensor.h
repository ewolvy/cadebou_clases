#ifndef sensor_h

#define sensor_h

#include <VL6180X.h>
#include <Wire.h>
#include "setup.h"

#define TYPE_VL 0
#define TYPE_IMU 1

void tca_select(uint8_t i);
void setup_sensor(uint8_t tca_addr, uint8_t type);
uint8_t read_mm(uint8_t address);

extern VL6180X sensor;

#endif