# Makefile for compiling a C project with multiple source files
#
# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g -Wall

# Linker flags
LDFLAGS = -lm  #link against math Library

# Target executable name
TARGET = fofx

# Source files
SRCS = fofx.c  # add other source files

# Object files (replace .c from SRCS with .o
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule for linking the final executable
# Depends on the object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule for compiling the source files into object files
# Generic rule for all source files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean target for removing compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
# .PHONY: all clean

