#include "monty.h"
#include <stdarg.h>

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
		eor(1);
		exit(EXIT_FAILURE);
	}
	ma_file = open_file(argv[1], "r");
	if (!ma_file)
    {
		eor(2, argv[1]);
        exit(EXIT_FAILURE);
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
				eor(3, line_number, ma_file, stack);
                exit(EXIT_FAILURE);
			}
			ma_push(&stack, atoi(token));
		} else if (strcmp(token, "pall") == 0)
			ma_pall(&stack, line_number);
		else
        {
			eor(4, line_number, token, *stack, ma_file);
            exit(EXIT_FAILURE);
        }
	}
	free_stack(stack);
	fclose(ma_file);
	return (EXIT_SUCCESS);
}

/**
 * eor - exit
 * @error_code: parameter
 * @...: parameter
 * Return: void
 */
void eor(int error_code, ...)
{
	va_list ag;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			fclose(va_arg(ag, FILE *));
			free_stack(va_arg(ag, stack_t *));
			break;
		case 4:
			fprintf(stderr, "L%d: unknown instruction %s\n",
					va_arg(ag, int), va_arg(ag, char *));
			free_stack(va_arg(ag, stack_t *));
			fclose(va_arg(ag, FILE *));
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
