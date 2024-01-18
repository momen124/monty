#include "monty.h"

/**
 * f_push - Add a node to the stack or queue
 * @head: Pointer to the head of the stack or queue
 * @counter: Line number
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
int n, j = 0;
int has_error = 0;

if (!bus.arg || strlen(bus.arg) == 0)
{
has_error = 1;
}
else
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (!isdigit(bus.arg[j]))
{
has_error = 1;
break;
}
}
}

if (has_error)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head, counter);
exit(EXIT_FAILURE);
}

n = atoi(bus.arg);
if (bus.lifi == 0)
addnode(head, n);
else
addqueue(head, n);
}
