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

/**
 * swap - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aide;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aide = (*stack)->next;
	(*stack)->next = aide->next;
	(*stack)->prev = aide;
	aide->next = *stack;
	aide->prev = NULL;
	*stack = aide;
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
