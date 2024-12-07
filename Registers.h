#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>

class Registers {
public:
    int programCounter;  // Tracks the current instruction address
    int accumulator;     // Stores the accumulator value
    int dataRegister;    // Stores the data register value
    bool zeroBit;        // Tracks if the last operation resulted in zero
    bool halted;         // Tracks if the program should halt
    bool executeAllFlag; // Tracks if command 'a' or 's' is used

    Registers();         // Constructor
    void reset();        // Resets all registers to their initial state
    void printState() const; // Prints the current state of the registers
};

#endif