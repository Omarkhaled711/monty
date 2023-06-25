#include "monty.h"

/**
 * get_first_string - Get the first string object
 *
 * @input: the input
 * Return: char*
 */
char *get_first_string(char *input)
{
	char *first_string = NULL;
	size_t len = strlen(input);
	size_t i = 0;

	/* Skip any leading spaces */
	while (i < len && isspace(input[i]))
		i++;

	/* Find the start of the first string */
	while (i < len && !isspace(input[i]))
		i++;

	/* Copy the first string into a new buffer */
	if (i > 0)
	{
		first_string = malloc(i + 1);
		if (first_string == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strncpy(first_string, input, i);
		first_string[i] = '\0';
	}
	return (first_string);
}
/**
 * get_first_integer - Get the first integer object
 *
 * @input: the input
 * @flag: if there's no int argument flag will be 0
 * Return: int
 */
int get_first_integer(char *input, int *flag)
{
	int first_integer = 0;
	size_t len = strlen(input);
	size_t i = 0;
	int sign = 1;

	*flag = 0;
	/* Skip any leading spaces */
	while (i < len && !isdigit(input[i]) && input[i] != '-')
		i++;
	/* Check for sign */
	if (i < len && input[i] == '-')
	{
		sign = -1;
		i++;
	}

	/* Find the start of the integer */
	while (i < len && isdigit(input[i]))
	{
		first_integer = first_integer * 10 + (input[i] - '0');
		i++;
		*flag = 1;
	}
	if (input[i] && !isspace(input[i]))
	{
		*flag = 0;
	}
	return (first_integer * sign);
}

/**
 * process_line - process each line in the input
 *
 * @input: the input
 * @stack: the stack
 * @line_num: the line number
 * Return: void
 */
void process_line(char *input, stack_t **stack, unsigned int line_num)
{
	char *cmd = get_first_string(input);
	int flag = 0;

	data = get_first_integer(input, &flag);
	execute(cmd, stack, line_num, flag);
}
