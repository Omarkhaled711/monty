#include "monty.h"

/**
 * execute - executes the commands
 *
 * @cmd: the command
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void execute(char *cmd, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int cmd_err = 1, i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(cmd, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			cmd_err = 0;
			break;
		}
	}
	if (cmd_err)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}
