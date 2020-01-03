#include "header.h"

void treat_token(stack_t **head, char *token)
{
	char *arg;
	instruction_t *ops;

	if (!strncmp("push", token, 4))
	{
		if ((arg = check_push_arg(token)) != NULL)
			push(head, line_number, arg);
	}
	
	ops = create_ops();

	/* cas 2 if opcode*/
	/* cas 3 if invalid*/
}

instruction_t *create_ops(void)
{
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

	return (ops);
}
