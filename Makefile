# First Makefile

# Compiler name
CC = gcc

# Compiler options / arguments
CFLAGS = -std=c99 -pedantic

# List all src files
SRC_FILES = $(wildcard src/*.c)

all: main

main:
	$(CC) -o soueu $(SRC_FILES) $(CFLAGS)

clean:
	rm soueu