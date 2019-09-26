#include "monty.h"

/**
 * op_stack - Set the format to stack (LIFO)
 * @stack: The stack
 * @line_number: The line number
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue = 0;
}

/**
 * op_queue - Set the format to queue (LIFO)
 * @stack: The stack
 * @line_number: The line number
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.queue = 1;
}
