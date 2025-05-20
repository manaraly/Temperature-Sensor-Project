# Makefile for Temperature Sensor Project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lm

# Source files and targets
SRC = temperature_sensor.c
TEST_SRC = test_temperature_sensor.c
EXAMPLE_SRC = example.c
TEST_TARGET = test_temperature_sensor
EXAMPLE_TARGET = example

# Default target
all: $(TEST_TARGET) $(EXAMPLE_TARGET)

# Build test executable
$(TEST_TARGET): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Build example executable
$(EXAMPLE_TARGET): $(SRC) $(EXAMPLE_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Run example
example: $(EXAMPLE_TARGET)
	./$(EXAMPLE_TARGET)

# Clean build artifacts
clean:
	rm -f $(TEST_TARGET) $(EXAMPLE_TARGET) *.o

.PHONY: all test example clean