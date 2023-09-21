#include "monty.h"

bfstruct buf;

int main (int argc, char *argv[])
{
	char limit[LIMIT_STACK], *token;
	int i = 0;

    buf.md = 0;
    buf.num_lines = 0;
	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	buf.mafile = open_file(argv[1], "r");
    if (!buf.mafile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
	while (fgets(limit, sizeof(limit), buf.mafile) != NULL)
	{
        if (strlen(trim(limit)) < 3 || trim(limit)[0] == '#')
        {
            buf.num_lines++;
            continue;
        }
		buf.num_lines++;
        token = strtok(limit, " \n");
        buf.opcode = NULL;
		for (i = 0; token != NULL && i < 2; i++)
        {
            if (i == 0)
                buf.opcode = token;
            if (strcmp(buf.opcode, "push") != 0)
                break;
            if (i == 1)
            {

                if (!is_numeric(token))
                {
                    fprintf(stderr, "L%d: usage: push integer\n", buf.num_lines);
                    free_stack(buf.first);
                    exit(EXIT_FAILURE);
                }
                buf.cmdtoken[i] = token;
            }
            token = strtok(NULL, " \n");
        }
        if (buf.opcode == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction\n", buf.num_lines);
            free_stack(buf.first);
            exit(EXIT_FAILURE);
        }
        do_it();

    }
	free_stack(buf.first);
	return (0);
}
void do_it(void)
{
	instruction_t ins[] = {
        {"push", ma_push},
		{"pall", ma_pall},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(buf.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&buf.first, buf.num_lines);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				buf.num_lines, buf.opcode);
		free_stack(buf.first);
		exit(EXIT_FAILURE);
	}
}