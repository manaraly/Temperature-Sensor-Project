/**
 * @file test_framework.h
 * @brief Simple test framework for C
 */

 #ifndef TEST_FRAMEWORK_H
 #define TEST_FRAMEWORK_H
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 
 /* Test counters */
 static int tests_run = 0;
 static int tests_passed = 0;
 static int tests_failed = 0;
 
 /* Macros for testing */
 #define ASSERT_TRUE(message, test) do { \
     tests_run++; \
     if (!(test)) { \
         printf("FAIL: %s\n", message); \
         tests_failed++; \
         return message; \
     } \
     tests_passed++; \
     return NULL; \
 } while (0)
 
 #define ASSERT_FLOAT_EQ(message, expected, actual, epsilon) do { \
     tests_run++; \
     if (fabs((expected) - (actual)) > (epsilon)) { \
         printf("FAIL: %s (expected: %f, got: %f)\n", message, (double)(expected), (double)(actual)); \
         tests_failed++; \
         return message; \
     } \
     tests_passed++; \
     return NULL; \
 } while (0)
 
 #define RUN_TEST(test) do { \
     char *message = test(); \
     if (message) { \
         printf("Test failed: %s\n", message); \
     } else { \
         printf("Test passed\n"); \
     } \
 } while (0)
 
 #define PRINT_TEST_RESULTS() do { \
     printf("\n----- TEST RESULTS -----\n"); \
     printf("Tests run: %d\n", tests_run); \
     printf("Tests passed: %d\n", tests_passed); \
     printf("Tests failed: %d\n", tests_failed); \
     printf("-----------------------\n"); \
 } while (0)
 
 #endif /* TEST_FRAMEWORK_H */