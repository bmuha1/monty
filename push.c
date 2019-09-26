#include "monty.h"

/**
 * op_push - Push an element to the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (global.argument == -7777)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	new->n = global.argument;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
