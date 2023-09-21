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
	stack_t *temp;
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
