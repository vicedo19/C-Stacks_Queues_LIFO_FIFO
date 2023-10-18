#include "monty.h"

/**
 * op_push - Function that pushes an element to the stack.
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->n = stack_value;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * op_pall - Function that prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_stack = *stack;
	(void)line_number;

	while (tmp_stack != NULL)
	{
		printf("%d\n", tmp_stack->n);
		tmp_stack = tmp_stack->next;
	}
}

/**
 * op_pint - Function that prints the value at the top of the stack
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - Function that removes the top element of the stack.
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_stack = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp_stack = tmp_stack->next;
	free(*stack);
	*stack = tmp_stack;
}

/**
 * op_swap - Function that swaps the top two elements of the stack
 *
 * @stack: Defined stack
 * @line_number: Line number to the file to process
 *
 * Return: 0
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_stack = *stack;
	int tmp_n;

	if (!tmp_stack || !tmp_stack->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp_stack = tmp_stack->next;
	tmp_n = tmp_stack->n;
	tmp_stack->n = (*stack)->n;
	(*stack)->n = tmp_n;
}
