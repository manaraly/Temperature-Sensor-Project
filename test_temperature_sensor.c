
#include <stdio.h>
#include <stdlib.h>
#include "test_framework.h"
#include "temperature_sensor.h"

/* Define epsilon for floating point comparisons */
#define EPSILON 0.001f

/**
 * Test case 1: Valid minimum input (0)
 */
static char *test_valid_min_input() {
    float result = convert_adc_to_temperature(0);
    ASSERT_FLOAT_EQ("Temperature should be 0.0 for ADC value 0", 0.0f, result, EPSILON);
}

/**
 * Test case 2: Valid maximum input (1023)
 */
static char *test_valid_max_input() {
    float result = convert_adc_to_temperature(1023);
    ASSERT_FLOAT_EQ("Temperature should be 100.0 for ADC value 1023", 100.0f, result, EPSILON);
}

/**
 * Test case 3: Valid middle input (511)
 */
static char *test_valid_mid_input() {
    float result = convert_adc_to_temperature(511);
    ASSERT_FLOAT_EQ("Temperature should be ~50.0 for ADC value 511", 49.95f, result, EPSILON);
}

/**
 * Test case 4: Invalid input below range (-1)
 */
static char *test_invalid_below_range() {
    float result = convert_adc_to_temperature(-1);
    ASSERT_FLOAT_EQ("Should return error code (-1.0) for ADC value -1", -1.0f, result, EPSILON);
}

/**
 * Test case 5: Invalid input above range (1024)
 */
static char *test_invalid_above_range() {
    float result = convert_adc_to_temperature(1024);
    ASSERT_FLOAT_EQ("Should return error code (-1.0) for ADC value 1024", -1.0f, result, EPSILON);
}

/**
 * Test case 6: Valid arbitrary input (256)
 */
static char *test_valid_arbitrary_input() {
    float result = convert_adc_to_temperature(256);
    ASSERT_FLOAT_EQ("Temperature should be ~25.0 for ADC value 256", 25.02f, result, EPSILON);
}

/**
 * Main function to run all tests
 */
int main(void) {
    printf("Running temperature sensor tests...\n\n");
    
    /* Run all test cases */
    RUN_TEST(test_valid_min_input);
    RUN_TEST(test_valid_max_input);
    RUN_TEST(test_valid_mid_input);
    RUN_TEST(test_invalid_below_range);
    RUN_TEST(test_invalid_above_range);
    RUN_TEST(test_valid_arbitrary_input);
    
    /* Print test results summary */
    PRINT_TEST_RESULTS();
    
    /* Return non-zero if any tests failed */
    return tests_failed > 0 ? 1 : 0;
}