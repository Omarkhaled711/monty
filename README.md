# Monty Interpreter in C

This project aims to implement a monty interpreter in C. Monty 0.98 is a scripting language that is compiled into Monty byte codes, similar to Python. It uses a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Monty byte code files are files with the extension `.m` that contain Monty byte codes. Each file has one instruction per line, and there can be any number of spaces before or after the opcode and its argument. The files can contain blank lines, and any additional text after the opcode or its required argument is ignored. Here is an example of a Monty byte code file:
```
push 0
push 1
push 2
push 3
pall
push 4
push 5
push 6
pall
smali
```

## The Monty Program

The `monty` program is used to execute Monty byte code files. The user must provide a valid monty file path as an argument to the application. If the user does not provide any file or more than one argument to the program, it prints the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.

If, for any reason, it’s not possible to open the file, the program prints the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`, where `<file>` is the name of the file.

If the file contains an invalid instruction, it prints the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`, where `<line_number>` is the line number where the instruction appears. Line numbers always start at 1.

If the program can’t allocate memory using `malloc`, an error message is printed `Error: malloc failed`, followed by a new line, and exit with the status `EXIT_FAILURE`. 

## Expected Behavior

The Monty interpreter reads Monty byte code files and executes the instructions line by line. The instructions manipulate a unique stack data structure. The interpreter supports the following instructions:

- `push`: pushes an integer onto the stack.
- `pall`: prints all the values on the stack.
- `pint`: prints the value at the top of the stack.
- `pop`: removes the top element of the stack.
- `swap`: swaps the top two elements of the stack.
- `add`: adds the top two elements of the stack.
- `nop`: does nothing.
- `sub`: subtracts the top element of the stack from the second top element.
- `div`: divides the second top element of the stack by the top element.
- `mul`: multiplies the second top element of the stack with the top element.
- `mod`: computes the rest of the division of the second top element of the stack by the top element.
- `pchar`: prints the char value of the top element of the stack.
- `pstr`: prints the string starting at the top of the stack.
- `rotl`: rotates the stack to the top.
- `rotr`: rotates the stack to the bottom.

If an invalid instruction is encountered, the interpreter should print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`, where `<line_number>` is the line number where the instruction appears. Line numbers always start at 1.

## Design

The Monty interpreter is implemented in C and divides the program execution into three stages: reading, processing, and execution.

In the reading stage, the interpreter reads the Monty byte code file line by line using the `getline` function. Each line is passed to the processing stage for further analysis.

In the processing stage, the interpreter extracts the opcode and any required arguments from the line. This information is then passed to the execution stage.

In the execution stage, the interpreter executes the opcode by calling the appropriate function. The functions are stored in an array of `instruction_t` structs, which contain the opcode and a pointer to the function that implements the opcode. The `stack_t` struct is used to implement the stack data structure that is manipulated by the instructions.

The `execute` function takes the opcode and any required arguments, the address of the stack, the line number, and a flag indicating if the opcode requires an argument. It searches for the opcode in the `instruction_t` array and calls the associated function if it is found. If the opcode is not found, or if there is an error in the arguments, it prints an error message and exits with `EXIT_FAILURE`.

## Credits
This project was completed as part of the curriculum requirements for the Alx Software Engineering program at Holberton School.
