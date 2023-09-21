#include "monty.h"

/**
 * main - check the code
 * @argc: parameter
 * @argv: parameter
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char limit[LIMIT_STACK], *token;
	FILE *ma_file;
	stack_t *stack = NULL;
	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ma_file = open_file(argv[1], "r");
	while (fgets(limit, LIMIT_STACK, ma_file))
	{
		if (strlen(limit) < 3 || limit[0] == '#')
		{
			line_number++;
			continue;
		}
		line_number++;
		token = strtok(limit, " \t\n");
		if (!token)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (!token || is_numeric(token) == 0)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(ma_file);
				exit(EXIT_FAILURE);
			}
			ma_push(&stack, atoi(token));
		} else
			call(&stack, token, line_number);
	}
	free_stack(stack);
	fclose(ma_file);
	return (EXIT_SUCCESS);
}

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
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
