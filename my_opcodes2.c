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

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * ma_pchar - prints the character at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pchar(stack_t **stack, int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
/**
 * ma_pstr - check the code
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_pstr(stack_t **stack, int line_number)
{
	stack_t *current = *stack;
	int ascii_value;

	(void) line_number;

	while (current != NULL)
	{
		ascii_value = current->n;
		if (ascii_value < 32 || ascii_value > 126 || ascii_value == 0)
		{
			break;
		}

		putchar((char)ascii_value);
		current = current->next;
	}
	putchar('\n');
}

/**
 * ma_rotl -  rotates the stack to the top.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_rotl(stack_t **stack, int line_number)
{
	stack_t *current, *topp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	topp = current->next;
	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->next = NULL;
	*stack = topp;
}

/**
 * ma_rotr -  rotates the stack to the top.
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: void
 */
void ma_rotr(stack_t **stack, int line_number)
{
	stack_t *current;
	stack_t *last = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stack;
	*stack = current;
}
