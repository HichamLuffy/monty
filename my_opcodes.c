#include "monty.h"
/**
 * ma_push - adds an element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
stack_t *ma_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void) line_number;

	if (!new)
	{
        if (*stack)
            free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new;
	}
	*stack = new;

	return (*stack);
}

/**
 * ma_pall -  prints all the values on the stack, starting from the top of the stack.
 * @stack: pointer to the top of the stack
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
	
	for (; tmp; tmp = tmp->next)
	{
		fprintf(stdout, "%d\n", tmp->n);
	}
	
}
