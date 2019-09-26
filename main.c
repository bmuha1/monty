#include "monty.h"

global_t global = {NULL, -7777};

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 *
 * Return: 0 for success, 1 otherwise
 */
int main(int argc, char **argv)
{
	char buf[1024];
	char t[128] = "";
	char t2[128] = "";
	char *token = t;
	char *token2 = t2;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fp = fopen(argv[1], "r");
	if (!(global.fp))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), global.fp))
	{
		token = strtok(buf, " ");
		token2 = strtok(NULL, " ");
		if (token2)
		{
			if (isdigit(token2[0]))
				global.argument = atoi(token2);
			else
				global.argument = -7777;
		}
		else
			global.argument = -7777;
		if (token[0] != '\n')
			get_opcode(&stack, token, line_number)(&stack,
						       line_number);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);
}
