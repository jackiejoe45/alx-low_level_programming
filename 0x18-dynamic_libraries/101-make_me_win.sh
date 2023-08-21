#!/bin/bash
gcc -shared -o libcustomrand.so -fPIC customrand.c
export LD_PRELOAD=./libcustomrand.so
