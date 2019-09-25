#include "monty.h"

/**
 * free_all - Free the stack
 * @stack: The stack
 */
void free_all(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
