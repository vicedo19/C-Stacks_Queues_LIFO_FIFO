#include "monty.h"

/**
 * op_add - Function that adds the top two elements of the stack.
 * The result is stored in the second top element of the stack,
 * and the top element is removed
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_stack = *stack;

	if (!tmp_stack || !tmp_stack->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp_stack = tmp_stack->next;
	tmp_stack->n += (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_nop - Function that doesnt do anything.
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
