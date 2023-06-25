#include "monty.h"

/**
 * get_first_string - Get the first string object
 *
 * @input: the input
 * @first_string: pointer to the string
 * Return: void
 */
void get_first_string(char *input, char **first_string)
{
	size_t len = strlen(input);
	size_t i = 0, j = 0;

	*first_string = malloc(len * sizeof(char));
	if (*first_string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Skip any leading spaces */
	while (i < len && isspace(input[i]))
		i++;

	/* Find the start of the first string */
	while (i < len && !isspace(input[i]))
	{
		(*first_string)[j] = input[i];
		i++;
		j++;
	}
	(*first_string)[j] = 0;
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
	if (i < len && isdigit(input[i]))
	{
		first_integer = atoi(&input[i]);
		i += strlen(&input[i]);
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
	char *cmd = NULL;
	int flag = 0;

	get_first_string(input, &cmd);
	data = get_first_integer(input, &flag);
	execute(cmd, stack, line_num, flag);
	free(cmd);
}
