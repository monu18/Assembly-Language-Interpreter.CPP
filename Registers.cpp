#include "Registers.h"

// Constructor
Registers::Registers()
    : programCounter(0), accumulator(0), dataRegister(0),
      zeroBit(false), halted(false), executeAllFlag(false) {}

// Resets the registers to their initial state
void Registers::reset() {
    programCounter = 0;
    accumulator = 0;
    dataRegister = 0;
    zeroBit = false;
    halted = false;
    executeAllFlag = false;
}

// Prints the current state of the registers
void Registers::printState() const {
    std::cout << "PC: " << programCounter
              << ", Register A: " << accumulator
              << ", Register B: " << dataRegister
              << ", Zero Bit: " << (zeroBit ? "True" : "False")
              << '\n';
}