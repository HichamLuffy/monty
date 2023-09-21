#include "monty.h"
/**
 * ma_nop - doing nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
*/
void ma_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * ma_sub - subtracts the top element of the stack from the second top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
*/
void ma_sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
/**
 * ma_div - divides the top element of the stack by the second top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
*/
void ma_div(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
