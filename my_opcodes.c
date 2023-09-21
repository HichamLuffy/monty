#include "monty.h"
/**
 * ma_push - adds an element to the stack of the stack
 * @stack: pointer to the stack of the stack
 * @line_number: line number
 * Return: void
 */
void ma_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;

    if (!stack)
    {
        fprintf(stderr, "L%d: stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = atoi(buf.cmdtoken[1]);
    new->prev = NULL;

    if (*stack)
    {
        new->next = *stack;
        (*stack)->prev = new;
    }
    else
    {
        new->next = NULL;
    }

    *stack = new;
}
/**
 * ma_pall -  prints all the values on the stack, starting from the stack of the stack.
 * @stack: pointer to the stack of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack)
    {
        fprintf(stderr, "L%d: can't pall, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
	
	while (tmp != NULL)
	{
		printf("%d\n", (tmp)->n);
        tmp = tmp->next;
	}
	
}
