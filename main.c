#include "monty.h"

bfstruct buf;

int main (int argc, char *argv[])
{
	char limit[LIMIT_STACK];
	FILE *ma_file;
	stack_t *stack = NULL;
	int i = 0, line_number = 0;
    void (*op_func)(stack_t **stack, unsigned int line_number) = NULL;

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
		buf.num_lines++;
		trim(limit);
		if (strlen(limit) == 0 || limit[0] == '#')
        {
            buf.num_lines++;
			continue;
        }
        buf.num_lines++;
		buf.cmdtoken[0] = strtok(limit, " \t\n");
		if (strcmp(buf.cmdtoken[0], "push") == 0)
		{
			buf.cmdtoken[1] = strtok(NULL, " \t\n");
			if (!buf.cmdtoken[1] || !is_numeric(buf.cmdtoken[1]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(ma_file);
				exit(EXIT_FAILURE);
			}
            else
                ma_push(&stack, atoi(buf.cmdtoken[1]));
		}
		else
		{
            op_func = get_op_func(buf.cmdtoken[0]);
            if (!op_func)
            {
                free_stack(stack);
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, buf.cmdtoken[0]);
                exit(EXIT_FAILURE);
            }
            (*get_op_func(buf.cmdtoken[0]))(&stack, line_number);
		}
        line_number++;
        i++;
	}

	free_stack(stack);
	fclose(ma_file);
	return (0);
}
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opf[] = {
		{"pall", ma_pall},
		{NULL, NULL},
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