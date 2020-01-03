#include "header.h"

void treat_line(stack_t **head, char *line, unsigned int line_number)
{
	char *token = NULL;

	token = strtok(line, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");
	if (!token)
		return;
	treat_token(head, token);
}
