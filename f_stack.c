#include "monty.h"
/**
 * free_stack - Function that frees a the stack
 *
 * @stack: The stack to free
 *
 * Return: 0
 */
void free_stack(stack_t *stack)
{
	stack_t *next_node;

	while (stack != NULL)
	{
		next_node = stack->next;
		free(stack);
		stack = next_node;
	}
}
