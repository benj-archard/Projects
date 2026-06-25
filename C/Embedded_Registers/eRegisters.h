#ifndef EREGISTERS_H

#define NUM_REGISTERS 8
#define MAX_CHARS     100

typedef enum {
    SET = 1,
    SET_BIT,
    CLEAR_BIT,
    TOGGLE_BIT,
    RESET,
    EXIT
}OPTIONS;


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


int readInput(char inputBuffer[], int bufferSize);
void readBinary(uint8_t registers[], int registerToRead);

int menu(char inputBuffer[], uint8_t registers[]);

void setRegister(char inputBuffer[],  uint8_t registers[]);
void resetRegister(char inputBuffer[], uint8_t registers[]);

void setBit(char inputBuffer[], uint8_t registers[]);
void clearBit(char inputBuffer[], uint8_t registers[]);
void toggleBit(char inputBuffer[], uint8_t registers[]);

#endif