#include "monty.h"
/**
 * main - Monty Interpreter
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		read_file(argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
