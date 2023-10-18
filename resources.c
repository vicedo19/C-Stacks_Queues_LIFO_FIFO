#include "monty.h"

/**
 * is_number - Function that validate if token is a number
 *
 * @token: A token to validate
 *
 * Return: 1 if is number and 0 if not a number
 */
int is_number(char *token)
{
	int i = 0;

	if (token == NULL)
		return (0);

	while (token[i] != '\0')
	{
		if (i == 0 && token[i] == '-')
			i++;

		if (!isdigit(token[i]))
			return (0);

		i++;
	}
	return (1);
}
