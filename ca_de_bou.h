#ifndef ca_de_bou_h

#define ca_de_bou_h

#include <Arduino.h>
#include "setup.h"
#include <ESP32Encoder.h>
#include "motor.h"
#include "sensor_distancia.h"

enum Orientacion
{
    N,
    S,
    E,
    O
};

typedef struct Estado
{
    Orientacion orientacion;
    uint8_t casilla_x;
    uint8_t casilla_y;
    int16_t posicion_x;
    int16_t posicion_y;
    int16_t posicion_alfa;
    int16_t velocidad_lineal;
    int16_t velocidad_angular;
} Estado;

typedef struct Deteccion_Paredes
{
    Orientacion orientacion;
    bool izquierda;
    bool frontal;
    bool derecha;
} Deteccion_Paredes;

class Ca_de_bou()
{
private:
    ESP32Encoder encoder_izq;
    ESP32Encoder encoder_dch;

    Motor motor_izq;
    Motor motor_dch;

    Sensor_Distancia dist_frontal_izq;
    Sensor_Distancia dist_frontal_dch;
    Sensor_Distancia dist_diagonal_izq;
    Sensor_Distancia dist_diagonal_dch;

    /* PARA EL FUTURO
    IMU imu;
    Bateria bateria;
    */

    Estado estado;

public:
    Ca_de_bou();

    /* FUNCIONES DE MOVIMIENTO */
    bool avanza(byte casillas);
    bool gira_derecha();
    bool gira_izquierda();
    bool media_vuelta();
    void parada_total();
    /* PARA EL FUTURO
    bool avanza(Estado estado_final);
    bool gira_derecha(Estado estado_final);
    bool gira_izquierda(Estado estado_final);
    */

    /* FUNCIONES DE DETECCIÓN */
    Estado ver_estado();
    Deteccion_Paredes ver_paredes();

    /* FUNCIONES DE CONTROL */
    void inicializa_posicion();
};

#endif