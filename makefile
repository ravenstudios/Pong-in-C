# Compiler and flags
CC = gcc
CFLAGS = -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lSDL2

# Target executable
TARGET = pong

# Source files
SRC = main.c sdl.c ball.c

# Object files (each .c file gets compiled into a corresponding .o file)
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (so Makefile doesn't look for files with these names)
.PHONY: all clean
