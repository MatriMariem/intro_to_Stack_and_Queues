#include <header.h>

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	if (*head == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
