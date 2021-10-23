#include "motores.h"
#include "setup.h"

void mover_motor(PinesMotores pines, int speed){
  Serial.print("velocidad: ");
  Serial.println(speed);
  if (speed > MAX_PWM_SPEED){
    speed = MAX_PWM_SPEED;
  }else if (speed < (0 - MAX_PWM_SPEED)){
    speed = 0 - MAX_PWM_SPEED;
  }
  if (speed == 0) {
    ledcWrite(pines.canal_adelante, LOW);
    ledcWrite(pines.canal_atras, LOW);
  } else if (speed > 0) {
    ledcWrite(pines.canal_adelante, speed);
    ledcWrite(pines.canal_atras, LOW);
  } else {
    ledcWrite(pines.canal_adelante, LOW);
    ledcWrite(pines.canal_atras, 0 - speed);
  }
}

void motor_full_stop(PinesMotores izq, PinesMotores dch){
  mover_motor(izq, 0);
  mover_motor(dch, 0);
}

void avanza(PinesMotores izq, PinesMotores dch, ESP32Encoder myEncoderLeft, ESP32Encoder myEncoderRight, uint8_t casillas){
  int32_t pasos_ant_l = myEncoderLeft.getCount();
  int32_t pasos_ant_r = myEncoderRight.getCount();
  int8_t velocidad_l = MAX_SPEED;
  int8_t velocidad_r = MAX_SPEED;
  int32_t pasos_left = pasos_ant_l;
  int32_t pasos_right = pasos_ant_r;
  while (pasos_left - pasos_ant_l < PASOS_CASILLA * casillas){
    pasos_left = myEncoderLeft.getCount();
    pasos_right = myEncoderRight.getCount();
    if (pasos_left > pasos_right){
      if (velocidad_r < MAX_SPEED){
        velocidad_r = MAX_SPEED;
      } else {
        velocidad_l = velocidad_l - 1;
      }
    } else if (pasos_right > pasos_left) {
      if (velocidad_l < MAX_SPEED){
        velocidad_l = MAX_SPEED;
      } else {
        velocidad_r = velocidad_r - 1;
      }
    }
    mover_motor(izq, velocidad_l);
    mover_motor(dch, velocidad_r);  
  }
  motor_full_stop(izq, dch);
}
