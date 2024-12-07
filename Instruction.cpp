#include "Instruction.h"
#include <iostream>
#include <stdexcept>

// DEC Instruction
DecInstruction::DecInstruction(const std::string& symbol) : Instruction("DEC"), symbol(symbol) {}

void DecInstruction::execute(Memory& memory, Registers& registers) {
    memory.allocateSymbol(symbol);
}

std::string DecInstruction::getDescription() const {
    return opcode + " " + symbol;
}

// LDI Instruction
LdiInstruction::LdiInstruction(int value) : Instruction("LDI"), value(value) {}

void LdiInstruction::execute(Memory& memory, Registers& registers) {
    registers.accumulator = value;
}

std::string LdiInstruction::getDescription() const {
    return opcode + " " + std::to_string(value);
}

// LDA Instruction
LdaInstruction::LdaInstruction(const std::string& symbol) : Instruction("LDA"), symbol(symbol) {}

void LdaInstruction::execute(Memory& memory, Registers& registers) {
    int address = memory.getAddress(symbol);
    registers.accumulator = memory.getData(address);
}

std::string LdaInstruction::getDescription() const {
    return opcode + " " + symbol;
}

// STR Instruction
StrInstruction::StrInstruction(const std::string& symbol) : Instruction("STR"), symbol(symbol) {}

void StrInstruction::execute(Memory& memory, Registers& registers) {
    int address = memory.getAddress(symbol);
    memory.setData(address, registers.accumulator);
}

std::string StrInstruction::getDescription() const {
    return opcode + " " + symbol;
}

// ADD Instruction
AddInstruction::AddInstruction() : Instruction("ADD") {}

void AddInstruction::execute(Memory& memory, Registers& registers) {
    int32_t result = registers.accumulator + registers.dataRegister;

    // Check for 16-bit overflow
    if (result < -32768 || result > 32767) {
        throw std::runtime_error("Overflow error in ADD operation.");
    }

    registers.accumulator = static_cast<int16_t>(result);
    registers.zeroBit = (registers.accumulator == 0);
}

std::string AddInstruction::getDescription() const {
    return opcode;
}

// SUB Instruction
SubInstruction::SubInstruction() : Instruction("SUB") {}

void SubInstruction::execute(Memory& memory, Registers& registers) {
    int32_t result = registers.accumulator - registers.dataRegister;

    // Check for 16-bit overflow
    if (result < -32768 || result > 32767) {
        throw std::runtime_error("Overflow error in SUB operation.");
    }

    registers.accumulator = static_cast<int16_t>(result);
    registers.zeroBit = (registers.accumulator == 0);
}

std::string SubInstruction::getDescription() const {
    return opcode;
}

// XCH Instruction
XchInstruction::XchInstruction() : Instruction("XCH") {}

void XchInstruction::execute(Memory& memory, Registers& registers) {
    std::swap(registers.accumulator, registers.dataRegister);
}

std::string XchInstruction::getDescription() const {
    return opcode;
}

// JMP Instruction
JmpInstruction::JmpInstruction(int address) : Instruction("JMP"), address(address) {}

void JmpInstruction::execute(Memory& memory, Registers& registers) {
    if (address < 0 || address > 127) {
        throw std::runtime_error("Invalid jump address.");
    }
    registers.programCounter = address;
}

std::string JmpInstruction::getDescription() const {
    return opcode + " " + std::to_string(address);
}

// JZS Instruction
JzsInstruction::JzsInstruction(int address) : Instruction("JZS"), address(address) {}

void JzsInstruction::execute(Memory& memory, Registers& registers) {
    if (registers.zeroBit) {
        if (address < 0 || address > 127) {
            throw std::runtime_error("Invalid jump address.");
        }
        registers.programCounter = address;
    }
}

std::string JzsInstruction::getDescription() const {
    return opcode + " " + std::to_string(address);
}

// HLT Instruction
HltInstruction::HltInstruction() : Instruction("HLT") {}

void HltInstruction::execute(Memory& memory, Registers& registers) {
    registers.halted = true;
}

std::string HltInstruction::getDescription() const {
    return opcode;
}