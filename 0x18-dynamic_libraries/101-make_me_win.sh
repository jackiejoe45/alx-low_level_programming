#!/bin/bash
gcc -shared -o libcustomrand.so -fPIC customrand.c
export LD_PRELOAD=./libcustomrand.so
./gm 9 8 10 24 75 9
