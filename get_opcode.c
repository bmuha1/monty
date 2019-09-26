#include "monty.h"

/**
 * get_opcode - Determine which opcode function to execute
 * @st: The stack
 * @s: The string containing the opcode
 * @lnum: The line number
 *
 * Return: The name of the function to execute
 */
void (*get_opcode(stack_t **st, char *s, int lnum))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"#", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};
	int i = 0;
	unsigned int j;

	while (ops[i].opcode)
	{
		for (j = 0; j < strlen(s); j++)
			if (s[j] == '\n')
				s[j] = '\0';
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lnum, s);
	free_all(st);
	exit(EXIT_FAILURE);
}
