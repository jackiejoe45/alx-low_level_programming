#!/bin/bash

# Compile each .c file into an object file
gcc -c -Wall -Werror -fpic *.c

# Create the dynamic library
gcc -shared -o liball.so *.o

# Clean up temporary object files
rm -f *.o
