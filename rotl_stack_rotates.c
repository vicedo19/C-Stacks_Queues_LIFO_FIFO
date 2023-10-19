#include "monty.h"

/**
  *stack_rotl- rotates the stack to the top
  *@head: stack head
  *@new_top_elem: line_number
  *Return: no return
 */

void stack_rotl(stack_t **head, stack_t *new_top_elem)
{
	stack_t *tmp = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new_top_elem = (*head)->next;
	new_top_elem->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = new_top_elem;
}
