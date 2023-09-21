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
        }
        else if (strcmp(token, "pall") == 0)
        {
            if (stack)
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
