# Learning C++ | 01 Calculator

## Objective
Practice parsing console input and structuring a simple command-driven program.

## Concepts Used
- std::string
- std::stringstream
- Control flow (if / switch)
- Basic input validation
- Functions

## How It Works
The program reads a full line from standard input using std::getline.
The input is parsed into two operands and one operator.
The operator determines which arithmetic operation is executed.
If the user types "exit", the main loop breaks and the program terminates.

## Limitations
Currently supports only two-integer operations.

## How to Build & Run
```bash
g++ main.cpp -o calculator
./calculator
```

## Possible Improvements
- Operations with more than 2 numbers.
- More operations.
- Support for floating-point numbers.
