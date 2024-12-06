#ifndef REGISTERS_H
#define REGISTERS_H

class Registers {
public:
    int programCounter;
    int accumulator;
    int dataRegister;
    bool zeroBit;
    bool halted;

    Registers() : programCounter(0), accumulator(0), dataRegister(0), zeroBit(false), halted(false) {}
};

#endif