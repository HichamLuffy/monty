#include "monty.h"
/**
 * ma_pop - deletes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pop(stack_t **stack, int line_number)
{
	stack_t *tmp = *stack;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!tmp->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	free(tmp);
}
