# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -L/usr/local/lib -lSDL2

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Target executable
TARGET = $(BUILD_DIR)/pong

# Source files and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile each .c file into a .o file in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up object files and the executable
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
