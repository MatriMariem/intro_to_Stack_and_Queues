#ifndef HEAD
#define HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern unsigned int line_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *str);
char *check_push_arg(char *token);

void treat_line(stack_t **head, char *line);

void treat_token(stack_t **head, char *token);
void (*get_function(char *token))(stack_t **, unsigned int);
void get_invalid_opcode(char *token);

void is_number(char *str);

void get_usage_err(void);

void pall(stack_t **head, unsigned int line_number);
#endif
