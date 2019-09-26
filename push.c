#include "monty.h"

/**
 * op_push - Push an element to the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char arg[128] = "";
	char *arg_p = arg;
	int argument;
	unsigned int i;

	arg_p = strtok(NULL, " \t");
	if (arg_p)
	{
		if (arg_p[0] == '\n')
			push_error(stack, line_number);
		for (i = 0; i < strlen(arg_p); i++)
		{
			if (!isdigit(arg_p[i]) && arg_p[0] != '-' &&
			    arg_p[i] != '\n')
				push_error(stack, line_number);
		}
		argument = atoi(arg_p);
	}
	else
		push_error(stack, line_number);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	new->n = argument;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * push_error - Print an error message and exit
 * @stack: The stack
 * @line_number: The line number
 */
void push_error(stack_t **stack, unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
		line_number);
	free_all(stack);
	exit(EXIT_FAILURE);
}
