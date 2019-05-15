#pragma once

#include <stdint.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define SIZE 100
#define OVERFLOW 1
#define ZERO_ERR 2
#define OUT_OF_MEM 0b00000001
#define FREQ_ERR 4
#define COMMAND_ERROR 0b00000100

int ram[SIZE];
int flags;

void errorHandler(int);
int sc_memoryInit();
int sc_memorySet(int, int);
int sc_memoryGet(int, int*);
int sc_memorySave(char*);
int sc_memoryLoad(char*);
int sc_regInit();
int sc_regSet(int, int);
int sc_regGet(int, int*);
int sc_commandEncode(int, int, int*);
int sc_commandDecode(int, int*, int*);


