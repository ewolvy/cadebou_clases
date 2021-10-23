#ifndef setup_h

#define setup_h

#include "i2cscan.h"
#include "sensor.h"

// Definiciones del multiplexor I2C
#define TCAADDR 0x70

// Definiciones de IMU
#define MPU 3
#define MPUADDR 0x68

// Definiciones de sensores de distancia
#define VLDIAGDCHA 0
#define VLDIAGIZQ 4
#define VLFRONDCHA 1
#define VLFRONIZQ 2

// Definiciones de encoders
#define LEFT_ENCODER_A_PIN 37
#define LEFT_ENCODER_B_PIN 36
#define RIGHT_ENCODER_A_PIN 26 
#define RIGHT_ENCODER_B_PIN 25

// Definiciones para los motores
#define FRECUENCIA_PWM 31250      // Frecuencia de los PWM del arduino
#define RESOLUCION_N_BITS_PWM 8   // CAMBIAR A LA VEZ QUE MAX_PWM_SPEED
#define MAX_PWM_SPEED 255         // CAMBIAR A LA VEZ QUE RESOLUCION_N_BITS_PWM
#define MAX_SPEED 64

#define LEFT_MOTOR_REV_PIN 33
#define LEFT_MOTOR_FWD_PIN 32
#define RIGHT_MOTOR_REV_PIN 27
#define RIGHT_MOTOR_FWD_PIN 13

#define LEFT_MOTOR_REV_CH 0
#define LEFT_MOTOR_FWD_CH 1
#define RIGHT_MOTOR_REV_CH 2
#define RIGHT_MOTOR_FWD_CH 3

#define PASOS_CASILLA 1000

#endif
