#include "header.h"

void push(stack_t **head, unsigned int line_number, char *arg)
{
	stack_t *h = *head, *new = NULL;
	int num = atoi(arg);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
	else
	{
		
	}
}

char *check_push_arg(char *token)
{
	char *token2;
	char *arg;
	int i, len;

	token2 = strtok(token, " \n");

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	for (len = 0; (token2[len] != '\n' && token2[len] != ' '); len++)
		;
	arg = malloc(sizeof(char) * (len + 1));
	if (!arg)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
		arg[i] = token2[i];
	arg[i] = '\0';

	if (is_number(arg))
		return (arg);
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
}

int is_number(char *str)
{
	if (strlen(str) == 1 && (str[0] - 48 == 0))
		return (1);
	if (atoi(str) == 0)
		return (0);
	return (1);
}
