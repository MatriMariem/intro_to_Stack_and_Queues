#include "header.h"

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	(void)line_number;

	if (*head == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
