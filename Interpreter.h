#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Memory.h"
#include "Registers.h"
#include "Instruction.h"
#include <vector>
#include <string>

class Interpreter {
private:
    Memory memory;
    Registers registers;
    std::vector<Instruction*> program;
    bool halted;
    int instructionCount; // Tracks the number of executed instructions

    void executeNext();
    void executeAll();
    void printFinalState() const;

public:
    Interpreter();
    void loadProgram(const std::string& filename);
    void runCommandLoop();
    ~Interpreter();
};

#endif