#!/bin/bash
clear
CFLAGS = -g -Wall -Werror -std=c99 -O0 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs 
rm *.o

gcc -c ./src/course1.c  -o course1.o  -DHOST  -DVERBOSE
gcc -c ./src/data.c     -o data.o     -DHOST  -DVERBOSE
gcc -c ./src/memory.c   -o memory.o   -DHOST  -DVERBOSE
gcc -c ./src/stats.c    -o stats.o    -DHOST  -DVERBOSE

gcc memory.o stats.o data.o course1.o ./src/main.c -o main.out -DHOST -DVERBOSE


ls -la *.o

./main.out