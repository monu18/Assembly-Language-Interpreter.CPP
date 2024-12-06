#include "Interpreter.h"
#include <iostream>

int main() {
    Interpreter interpreter;

    try {
        std::cout << "Enter the SAL program file name: ";
        std::string filename;
        std::cin >> filename;

        interpreter.loadProgram(filename);
        interpreter.runCommandLoop();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}