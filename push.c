#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (bus.arg == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head, counter);
        exit(EXIT_FAILURE);
    }

    if (bus.arg[0] == '-')
        j++;

    for (; bus.arg[j] != '\0'; j++)
    {
        if (!isdigit(bus.arg[j]))
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
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
