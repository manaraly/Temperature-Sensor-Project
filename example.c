/**
 * @file example.c
 * @brief Example usage of temperature sensor functionality
 */

 #include <stdio.h>
 #include "temperature_sensor.h"
 
 int main(void) {
     int adc_values[] = {0, 256, 511, 767, 1023, -10, 1100};
     int num_values = sizeof(adc_values) / sizeof(adc_values[0]);
     
     printf("Temperature Sensor Example\n");
     printf("=========================\n\n");
     
     for (int i = 0; i < num_values; i++) {
         int adc_value = adc_values[i];
         float temperature = convert_adc_to_temperature(adc_value);
         
         printf("ADC Value: %4d | ", adc_value);
         
         if (temperature >= 0.0f) {
             printf("Temperature: %.2f°C\n", temperature);
         } else {
             printf("Error: Invalid ADC value\n");
         }
     }
     
     return 0;
 }