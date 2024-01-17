#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head, unsigned int counter)
{
	stack_t *aux;
(void)counter;
	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
