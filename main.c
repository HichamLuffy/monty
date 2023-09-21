#include "monty.h"


int main (int argc, char *argv[])
{
    char limit[LIMIT_STACK], *token;
    FILE *ma_file;
    stack_t *stack = NULL;
    int line_number = 0;

    if (argc != 2)
    {
        printf("Usage: monty file\n");
        exit(EXIT_FAILURE);
    }
    ma_file = open_file(argv[1], "r");
    if (!ma_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(limit, LIMIT_STACK, ma_file))
    {
        trim(limit);
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
                exit(EXIT_FAILURE);
            }
            else
                ma_push(&stack, atoi(token));
        }
        else if (strcmp(token, "pall") == 0)
        {
            ma_pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
            if (stack)
                free_stack(stack);
            fclose(ma_file);
            exit(EXIT_FAILURE);
        }
        
    }

    free_stack(stack);
    fclose(ma_file);
    return (EXIT_SUCCESS);
}

/**
 * get_op_func - Retrieves the corresponding function pointer
 *  based on the opcode.
 * @s: The opcode string.
 *a
 * Return: Pointer to the corresponding function, or NULL if opcode not found.
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opf[] = {
		{"pall", ma_pall},
		{NULL, NULL}
	};

	int i = 0;

	while (opf[i].opcode)
	{
		if (strncmp(s, opf[i].opcode, (strlen(s))) == 0)
		{
			return (opf[i].f);
		}
		i++;
	}
	return (NULL);
}