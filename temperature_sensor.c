
#include "temperature_sensor.h"

float convert_adc_to_temperature(int adc_value) {
    /* Input validation */
    if (adc_value < 0 || adc_value > 1023) {
        return -1.0f; /* Error code for invalid input */
    }
    
    /* Convert ADC value to temperature using linear conversion */
    float temperature = ((float)adc_value / 1023.0f) * 100.0f;
    
    return temperature;
}