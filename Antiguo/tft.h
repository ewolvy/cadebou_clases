#ifndef tft_h

#define tft_h

#include <TFT_eSPI.h>
#include "esp_adc_cal.h"

#define ADC_PIN 34
#define ADC_EN 14  //ADC_EN is the ADC detection enable port

void show_voltage();
void setup_tft();

#endif