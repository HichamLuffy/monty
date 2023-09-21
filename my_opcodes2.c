#include "monty.h"
/**
 * ma_pop - deletes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
    tmp = *stack;
    *stack = tmp->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(tmp);
}
