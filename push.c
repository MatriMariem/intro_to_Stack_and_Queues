#include "header.h"

void push(stack_t **head, unsigned int line_number, char *arg)
{
	stack_t *new = NULL;
	int num = atoi(arg);

	(void)line_number;

	free(arg);
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
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
}

char *check_push_arg(char *token)
{
	char *token2;
	char *arg;
	int i, len;

	(void)token;

	token2 = strtok(NULL, " \n");
	printf("TOKEN 2 = %s\n", token2);

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
		get_usage_err();
	printf("BEFORE LOOP\n");
	for (len = 0; (token2[len] && token2[len] != '\n' && token2[len] != ' '); len++)
		;
	printf("AFTER LOOP\n");

	arg = malloc(sizeof(char) * (len + 1));
	if (!arg)
		get_usage_err();

	for (i = 0; i < len; i++)
		arg[i] = token2[i];
	arg[i] = '\0';

	is_number(arg);

	return (arg);
}

void get_usage_err(void)
{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
}

void is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			get_usage_err();
	}
	return;
}
