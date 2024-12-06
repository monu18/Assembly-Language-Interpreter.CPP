#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

// Constructor: Initializes the interpreter state
Interpreter::Interpreter() : instructionCount(0), halted(false) {}

void Interpreter::loadProgram(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string opcode, arg;
        iss >> opcode >> arg;

        try {
            if (opcode == "DEC") {
                program.push_back(new DecInstruction(arg));
            } else if (opcode == "LDI") {
                program.push_back(new LdiInstruction(std::stoi(arg)));
            } else if (opcode == "LDA") {
                program.push_back(new LdaInstruction(arg));
            } else if (opcode == "STR") {
                program.push_back(new StrInstruction(arg));
            } else if (opcode == "ADD") {
                program.push_back(new AddInstruction());
            } else if (opcode == "SUB") {
                program.push_back(new SubInstruction());
            } else if (opcode == "XCH") {
                program.push_back(new XchInstruction());
            } else if (opcode == "JMP") {
                program.push_back(new JmpInstruction(std::stoi(arg)));
            } else if (opcode == "JZS") {
                program.push_back(new JzsInstruction(std::stoi(arg)));
            } else if (opcode == "HLT") {
                program.push_back(new HltInstruction());
            } else {
                throw std::runtime_error("Unknown opcode: " + opcode);
            }

            std::cout << "Loaded instruction: " << opcode << " " << arg << '\n';

        } catch (const std::exception& e) {
            std::cerr << "Error processing line: " << line << "\n" << e.what() << '\n';
        }
    }
}

void Interpreter::executeNext() {
    if (halted || registers.programCounter >= program.size()) {
        halted = true;
        printFinalState();
        return;
    }

    // Fetch and execute the current instruction
    auto* instr = program[registers.programCounter];

    // Execute the instruction
    instr->execute(memory, registers);

    // Check if halted after execution
    if (registers.halted) {
        halted = true;
        printFinalState();
        return;
    }

    // Increment the program counter unless it's a jump
    ++registers.programCounter;

    // Print state and memory for after each execution
    if (!halted && registers.programCounter < program.size()) {
        std::cout << "PC: " << registers.programCounter
                  << ", Register A: " << registers.accumulator
                  << ", Register B: " << registers.dataRegister
                  << ", Zero Bit: " << registers.zeroBit << '\n';

        std::cout << "Program Memory State: \n";
        std::cout << "Memory[" << registers.programCounter - 1 << "] = " << instr->getDescription() << '\n';

        std::cout << "Data Memory State: \n";
        memory.printSymbolTable();
    }
}

void Interpreter::executeAll() {
    while (!halted && registers.programCounter < program.size()) {
        // Suppress intermediate output here by avoiding extra printing in executeNext
        auto* instr = program[registers.programCounter];
        instr->execute(memory, registers);

        // Check if halted after execution
        if (registers.halted) {
            halted = true;
            break;
        }

        // Increment the program counter unless it's a jump
        ++registers.programCounter;
    }

    // After execution, print the final state
    printFinalState();
}

void Interpreter::printFinalState() const {
    std::cout << "Program halted.\n";
    std::cout << "PC: " << registers.programCounter
              << ", Register A: " << registers.accumulator
              << ", Register B: " << registers.dataRegister
              << ", Zero Bit: " << registers.zeroBit << '\n';

    // Print program memory state
    std::cout << "Program Memory State: \n";
    for (size_t i = 0; i < program.size(); ++i) {
        std::cout << "Memory[" << i << "] = " << program[i]->getDescription() << '\n';
    }

    // Print data memory state
    std::cout << "Data Memory State: \n";
    memory.printSymbolTable();
}

void Interpreter::runCommandLoop() {
    std::cout << "Simple Assembly Language Interpreter\n";
    std::cout << "Developed by Monu Kumar\n\n";

    std::string command;
    while (true) {
        std::cout << "Enter command (s: step, a: run all, q: quit): ";
        std::cin >> command;
        if (command == "s") {
            if (halted) {
                std::cout << "Program already halted.\n";
                break;
            }
            executeNext();
        } else if (command == "a") {
            executeAll();
            break;
        } else if (command == "q") {
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    std::cout << "Terminating program...\nGood Bye!\n";
}

Interpreter::~Interpreter() {
    for (auto* instr : program) {
        delete instr;
    }
}