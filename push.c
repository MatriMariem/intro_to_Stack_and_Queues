#include "header.h"

void push(stack_t **stack, unsigned int line_number, char *str)
{

}

char *check_push_arg(char *token)
{
	char *token2;
	char *arg;

	token2 = strtok(token, " \n");

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
		return (NULL);

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
	return (arg);
}
