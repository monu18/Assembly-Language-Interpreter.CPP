#ifndef MEMORY_H
#define MEMORY_H

#include <map>
#include <vector>
#include <string>
#include <stdexcept>

class Memory {
private:
    std::map<std::string, int> symbolTable;
    std::vector<int> dataMemory;
    std::vector<std::string> programMemory;
    int nextAvailableAddress;

public:
    Memory() : dataMemory(128, 0), programMemory(128), nextAvailableAddress(128) {}

    int allocateSymbol(const std::string& symbol);
    int getAddress(const std::string& symbol) const;
    int getData(int address) const;
    void setData(int address, int value);
    const std::string& getProgramInstruction(int address) const;
    void setProgramInstruction(int address, const std::string& instruction);
    void printSymbolTable() const;
};

#endif