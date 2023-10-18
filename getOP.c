#include "monty.h"
/**
 * get_op_func - Function that selects the function to perform the operation
 * asked by the user
 *
 * @s: String with the name of function
 *
 * Return: 0
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
