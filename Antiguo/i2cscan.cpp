#include <Arduino.h>
#include <Wire.h>
#include "i2cscan.h"

/*
La función find_i2c se encarga de buscar todas las direcciones i2c que pueden
existir para crear una estructura de tipo I2CScan que indica el total de
dispositivos y las direcciones de éstos.
*/

I2CScan find_i2c (){
  bool devices[128] = {false};
  byte error;
  int nDevices = 0;

  Serial.println("Escaneando...");
  // Bucle para revisar las direcciones I2C de una en una
  for(byte address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    // Si el código de error es 0 significa que hay un dispositivo
    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado en la dirección 0x");
      serial_print_address(address);
      nDevices++;
      devices[address] = true;
    }
    // Si el código es 4 significa que hay algún error desconocido
    else if (error==4) {
      Serial.print("Error desconocido en la dirección 0x");
      serial_print_address(address);
    }
  }

  // Indicar si se ha encontrado algo
  if (nDevices == 0) {
    Serial.println("No se han encontrado dispositivos I2C\n");
  }
  else {
    Serial.println("Finalizado");
  }

  // Pasar los datos encontrados (si los hay) a una estructura de datos
  I2CScan result;
  result.total = nDevices;
  if (nDevices != 0){
    result.devices = new int[nDevices];
    int index = 0;
    for (int i = 1; i < 127; i++){
      if (devices[i]){
        result.devices[index] = i;
        index++;
      }
    }
  }
  return result;
}


/*
La función serial_print_address sirve para pasar por puerto serie un número
en formato decimal a formato hexadecimal de 2 dígitos (e.g: 15 -> 0F, 17 -> 12).
Se recomienda haber enviado antes el '0x'
*/

void serial_print_address (int address){
  if (address<16) {
    Serial.print("0");
  }
  Serial.println(address, HEX);
}

/*
La función realiza_escaneo_i2c sirve para ejecutar la función find_i2c y enviar
los resultados al puerto serie. Básicamente es para hacer un test y ver qué
se detecta.
*/

void realiza_escaneo_i2c (){
  I2CScan i2c;
  i2c = find_i2c ();
  Serial.print("Se ha(n) encontrado un total de ");
  Serial.print(i2c.total);
  Serial.println(" dispositivo(s).");
  if (i2c.total != 0){
    for (int i = 0; i < i2c.total; i++){
      Serial.print("Dispositivo encontrado en 0x");
      serial_print_address (i2c.devices[i]);
    }
  }
}