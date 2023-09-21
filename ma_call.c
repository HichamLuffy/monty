#include "monty.h"

/**
 * call - executes a command
 * @stack: pointer to the top of the stack
 * @instruction: instruction
 * @line_number: line number
 * Return: void
 */

void call(stack_t **stack, const char *instruction, int line_number)
{
	if (strcmp(instruction, "pall") == 0)
		ma_pall(stack, line_number);
	else if (strcmp(instruction, "pop") == 0)
		ma_pop(stack, line_number);
	else if (strcmp(instruction, "pint") == 0)
		ma_pint(stack, line_number);
	else if (strcmp(instruction, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(instruction, "add") == 0)
		add(stack, line_number);
	else if (strcmp(instruction, "nop") == 0)
		ma_nop(stack, line_number);
	else if (strcmp(instruction, "sub") == 0)
		ma_sub(stack, line_number);
	else if (strcmp(instruction, "div") == 0)
		ma_div(stack, line_number);
	else if (strcmp(instruction, "mul") == 0)
		ma_mul(stack, line_number);
	else if (strcmp(instruction, "mod") == 0)
		ma_mod(stack, line_number);
	else if (strcmp(instruction, "pchar") == 0)
		ma_pchar(stack, line_number);
	else if (strcmp(instruction, "pstr") == 0)
		ma_pstr(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
