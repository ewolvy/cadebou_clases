#ifndef i2cscan_h
#define i2cscan_h

typedef struct I2CScan{
  int total;
  int *devices;
}I2CScan;

I2CScan find_i2c ();
void serial_print_address (int address);
void realiza_escaneo_i2c ();

#endif