#include "header.h"

void treat_token(stack_t **head, char *token)
{
	char *arg;
	void (*f)(stack_t **head, unsigned int line_number);

	if (!strncmp("push", token, 4))
	{
		if ((arg == check_push_arg(token)) != NULL)
		{
			push(head, line_number, arg);
			return;
		}
	}

	f = get_function(token);

	if (!f)
	{
		get_invalid_opcode(token);
	}

	f(head, line_number);
}

void (*get_function(char *token))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (!strncmp(token, ops[i].opcode, strlen(ops[i].opcode)))
			return (ops[i].f);
	}

	return (NULL);
}

void get_invalid_opcode(char *token)
{
	int i, len;
	char *invalid_opcode;

	for (len = 0; (token[len] != ' ' && token[len] != '\n'); len++)
		;
	invalid_opcode = malloc(sizeof(char) * (len));
	if (!invalid_opcode)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
		invalid_opcode[i] = token[i];
	dprintf(STDERR_FILENO,
			"L%d: unknown instruction %s\n",
			line_number, invalid_opcode);
	free(invalid_opcode);
	exit(EXIT_FAILURE);
}




