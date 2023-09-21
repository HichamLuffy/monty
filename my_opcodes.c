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
		(*stack)->prev = new;
	*stack = new;

	return (*stack);
}

/**
 * ma_pall -  prints all the elements of the stack
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
	while (tmp != NULL)
	{
		printf("%d\n", (tmp)->n);
		tmp = tmp->next;
	}
}

/**
 * ma_pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}