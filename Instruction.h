#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include "Memory.h"
#include "Registers.h"

class Instruction {
protected:
    std::string opcode;

public:
    explicit Instruction(const std::string& opcode) : opcode(opcode) {}
    virtual void execute(Memory& memory, Registers& registers) = 0;
    virtual std::string getDescription() const = 0;
    virtual ~Instruction() = default;
};

class DecInstruction : public Instruction {
private:
    std::string symbol;

public:
    explicit DecInstruction(const std::string& symbol);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class LdiInstruction : public Instruction {
private:
    int value;

public:
    explicit LdiInstruction(int value);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class LdaInstruction : public Instruction {
private:
    std::string symbol;

public:
    explicit LdaInstruction(const std::string& symbol);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class StrInstruction : public Instruction {
private:
    std::string symbol;

public:
    explicit StrInstruction(const std::string& symbol);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class AddInstruction : public Instruction {
public:
    AddInstruction();
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class SubInstruction : public Instruction {
public:
    SubInstruction();
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class XchInstruction : public Instruction {
public:
    XchInstruction();
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class JmpInstruction : public Instruction {
private:
    int address;

public:
    explicit JmpInstruction(int address);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class JzsInstruction : public Instruction {
private:
    int address;

public:
    explicit JzsInstruction(int address);
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

class HltInstruction : public Instruction {
public:
    HltInstruction();
    void execute(Memory& memory, Registers& registers) override;
    std::string getDescription() const override;
};

#endif