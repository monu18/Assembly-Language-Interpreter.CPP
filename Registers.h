#ifndef REGISTERS_H
#define REGISTERS_H

class Registers {
public:
    int programCounter;  // Tracks the current instruction address
    int accumulator;     // Stores the accumulator value
    int dataRegister;    // Stores the data register value
    bool zeroBit;        // Tracks if the last operation resulted in zero
    bool halted;         // Tracks if the program should halt

    Registers() : programCounter(0), accumulator(0), dataRegister(0), zeroBit(false), halted(false) {}
};

#endif