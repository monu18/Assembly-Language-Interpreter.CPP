#include "Memory.h"
#include <iostream>

int Memory::allocateSymbol(const std::string& symbol) {
    if (symbolTable.find(symbol) == symbolTable.end()) {
        if (nextAvailableAddress >= 256) {
            throw std::runtime_error("Data memory full.");
        }
        symbolTable[symbol] = nextAvailableAddress++;
    }
    return symbolTable[symbol];
}

int Memory::getAddress(const std::string& symbol) const {
    auto it = symbolTable.find(symbol);
    if (it == symbolTable.end()) {
        throw std::runtime_error("Symbol not found: " + symbol);
    }
    return it->second;
}

int Memory::getData(int address) const {
    if (address < 128 || address >= 256) {
        throw std::runtime_error("Address out of bounds.");
    }
    return dataMemory[address - 128];
}

void Memory::setData(int address, int value) {
    if (address < 128 || address >= 256) {
        throw std::runtime_error("Address out of bounds.");
    }
    dataMemory[address - 128] = value;
}

const std::string& Memory::getProgramInstruction(int address) const {
    if (address < 0 || address >= 128) {
        throw std::runtime_error("Address out of bounds.");
    }
    return programMemory[address];
}

void Memory::setProgramInstruction(int address, const std::string& instruction) {
    if (address < 0 || address >= 128) {
        throw std::runtime_error("Address out of bounds.");
    }
    programMemory[address] = instruction;
}

void Memory::printSymbolTable() const {
    for (const auto& entry : symbolTable) {
        const std::string& symbol = entry.first;
        int address = entry.second;

        if (address < 128 || address >= 256) {
            std::cerr << "Invalid memory address for symbol: " << symbol << '\n';
            continue;
        }

        int value = dataMemory[address - 128]; // Adjust address to access data memory
        std::cout << symbol << " = " << value << '\n';
    }
}