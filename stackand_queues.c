#include "monty.h"
/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void find_queue(stack_t **head, unsigned int line_number)
{

	(void)head;
	(void)line_number;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no retur
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *new_elem;

	new_elem = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (new_elem)
	{
		while (new_elem->next)
			new_elem = new_elem->next;
	}
	if (!new_elem)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_elem->next = new_node;
		new_node->prev = new_elem;
	}
}
