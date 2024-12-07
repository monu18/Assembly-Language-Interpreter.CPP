# Simple Assembly Language (SAL) Interpreter (C++)

## Overview
This C++ implementation of a Simple Assembly Language Interpreter (ALI) simulates a basic assembly language environment. The interpreter follows the Command design pattern and provides functionality for executing assembly-like instructions with a virtual machine architecture.

## Features
- Virtual machine with program and data memory
- Register-based architecture (Accumulator and Data Register)
- Command-line interface for interactive execution
- Support for step-by-step debugging
- Implementation of the Command design pattern

## System Requirements
- C++ compiler with C++11 support (g++ or clang++)
- Standard C++ libraries
- Terminal/Command prompt

## Project Structure
```
.
├── main.cpp      # Program entry point
├── Command.h     # Abstract Command class and instruction declarations
├── Command.cpp   # Instruction implementations
├── ALI.h        # ALI class declaration
├── ALI.cpp      # ALI class implementation
└── README.md    # This file
```

## Compilation
To compile the program, use one of the following commands:

Using g++:
```bash
g++ -std=c++11 main.cpp ali.cpp command.cpp -o ali
```

Using clang++:
```bash
clang++ -std=c++11 main.cpp ali.cpp command.cpp -o ali
```

## Usage
1. Run the compiled program:
```bash
./ali
```

2. When prompted, enter the name of your SAL program file.

3. Use the following commands in the interactive prompt:
   - `s`: Execute a single instruction
   - `a`: Execute all instructions until halt
   - `q`: Quit the interpreter

## Instruction Set
The interpreter supports the following SAL instructions:

| Instruction | Description |
|------------|-------------|
| DEC symbol | Declare a symbolic variable |
| LDA symbol | Load value from memory into accumulator |
| LDI value  | Load immediate value into accumulator |
| STR symbol | Store accumulator value in memory |
| XCH        | Exchange accumulator and data register |
| JMP number | Jump to specified instruction |
| JZS number | Jump if zero flag is set |
| ADD        | Add accumulator and data register |
| SUB        | Subtract data register from accumulator |
| HLT        | Halt program execution |

## Example SAL Program
```
DEC sum     ; Declare variable sum
LDI 10      ; Load 10 into accumulator
STR sum     ; Store in sum
LDI 5       ; Load 5 into accumulator
XCH         ; Exchange A and B registers
LDA sum     ; Load sum into accumulator
ADD         ; Add A and B
STR sum     ; Store result in sum
HLT         ; Halt program
```

## Memory Architecture
- Program Memory: 128 locations (0-127)
- Data Memory: 128 locations (128-255)
- 16-bit word size
- Support for 2's complement integers (-32,768 to 32,767)

## Implementation Notes
1. Uses Command design pattern with an abstract Command class
2. Each instruction type is implemented as a concrete Command subclass
3. Memory is managed using separate program and data segments
4. Includes safety checks for arithmetic overflow
5. Supports infinite loop detection with user prompts

## Error Handling
- Validates memory access bounds
- Checks for arithmetic overflow
- Handles file I/O errors
- Validates instruction format

## Limitations
- No support for comments in SAL programs
- Limited error checking on input programs
- No support for floating-point operations
- Maximum program size of 128 instructions

## Contributing
This is an academic project. Please note that while suggestions for improvements are welcome, contributions should adhere to academic integrity policies.

## License
Copyright © 2024. All rights reserved.
This project cannot be copied, distributed, or reposted without the copyright owner's written consent.
