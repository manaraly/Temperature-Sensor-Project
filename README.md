# Temperature Sensor Project

This project implements a simple temperature sensor data processing functionality in C. It includes a function to convert raw ADC (Analog-to-Digital Converter) values from a temperature sensor to temperature in Celsius, along with comprehensive unit tests.

## Project Structure

```
temperature_sensor_project/
├── temperature_sensor.h     # Header file defining the sensor API
├── temperature_sensor.c     # Implementation of the sensor functionality
├── test_framework.h         # Simple test framework for C
├── test_temperature_sensor.c # Unit tests for the sensor functionality
├── example.c                # Example usage of the temperature sensor
├── Makefile                 # Build configuration
└── README.md                # This file
```

## Requirements

- C compiler (GCC recommended)
- Make build system
- Standard C libraries

## Building and Testing

To build and run the tests:

```bash
# Build the project
make

# Run tests
make test

# Run example
make example

# Clean the build artifacts
make clean
```

## Function Documentation

The main function provided by this project is:

```c
float convert_adc_to_temperature(int adc_value);
```

### Parameters

- `adc_value`: Raw ADC value from the temperature sensor (0-1023)

### Return Value

- Temperature in Celsius (0-100°C) for valid inputs
- -1.0 for invalid inputs (outside the range 0-1023)

### Description

This function converts raw ADC values from a temperature sensor to temperature in Celsius using a linear conversion formula: `temp_c = (adc_value / 1023.0) * 100.0`.

## Test Cases

The project includes the following test cases:

1. Valid minimum input (0)
2. Valid maximum input (1023)
3. Valid middle input (511)
4. Invalid input below range (-1)
5. Invalid input above range (1024)
6. Valid arbitrary input (256)

## Example Usage

```c
#include "temperature_sensor.h"
#include <stdio.h>

int main() {
    int adc_value = 512;
    float temperature = convert_adc_to_temperature(adc_value);
    
    if (temperature >= 0.0f) {
        printf("Temperature: %.2f°C\n", temperature);
    } else {
        printf("Error: Invalid ADC value\n");
    }
    
    return 0;
}
```
