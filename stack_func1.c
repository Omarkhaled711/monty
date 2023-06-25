#include "monty.h"

/**
 * push - push element to stack
 *
 * @stack: stack
 * @line_num: the line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_item;

	(void) line_num;
	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_item->n = data;
	new_item->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_item;
	*stack = new_item;
}

/**
 * pall - prints elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	(void) line_num;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
