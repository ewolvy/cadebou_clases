#ifndef motor_h

#define motor_h

#include <Arduino.h>
#include "setup.h"

typedef struct PinesMotor
{
    uint8_t pin_adelante, pin_atras;
    uint8_t canal_adelante, canal_atras;
} PinesMotor;

class Motor()
{
private:
    PinesMotor mis_pines;

public:
    Motor(PinesMotor pines);

    void velocidad(int16_t speed);
}

#endif