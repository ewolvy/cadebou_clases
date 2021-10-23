#ifndef sensor_distancia_h

#define sensor_distancia_h

#include <VL6180X.h>
#include <Wire.h>
#include "setup.h"

class Sensor_Distancia()
{
private:
    uint8_t id;
    void tca_select();
    VL6180X sensor;

public:
    Sensor_Distancia(uint8_t direccion);
    uint8_t leer_mm();
}

#endif