#include "sensor.h"

VL6180X sensor; // Se usa un solo objeto para todos los sensores

/*
La función tca_select sirve para seleccionar dentro del multiplexor
TCA9548A qué sensor I2C se va a usar
*/

void tca_select(uint8_t i) {
  if (i > 7) return;  // El TCA9548A usado admite 8 dispositivos
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

/*
La función setup_sensor inicializa el sensor indicado que puede ser de tipo
VL6180X (distancia) o IMU GY-521 (acelerómetro y giroscopio). Es importante
inicializar todos los sensores desde el programa principal en la función setup()
*/

void setup_sensor(uint8_t address, uint8_t type){
  tca_select(address);
  switch(type){
    case TYPE_VL:
    {
      sensor.init();
      sensor.configureDefault();
      sensor.setTimeout(500);
      sensor.setScaling(3);
      break;
    }
    case TYPE_IMU:
    {
      break;
    }
  }
}

/*
La función read_mm devuelve la lectura del sensor de distancia VL6180X indicado.
La propio función se encarga de seleccionar la dirección del TCA.
*/

uint8_t read_mm(uint8_t address){
  tca_select(address);

  return sensor.readRangeSingleMillimeters();
}