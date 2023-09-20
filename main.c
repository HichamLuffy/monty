#include "monty.h"


int main (int argc, char *argv[])
{
    char limit[LIMIT_STACK], *token;
    FILE *ma_file;
    int value;
    stack_t *stack = NULL;
    int line_number = 0;

    if (argc != 2)
    {
        printf("Usage: monty file\n");
        exit(EXIT_FAILURE);
    }
    ma_file = open_file(argv[1]);
    while (fgets(limit, LIMIT_STACK, ma_file) != NULL)
    {
        line_number++;
        trim(limit);
        if (strlen(limit) == 0 || limit[0] == '#')
            continue;
        token = strtok(limit, " \t\n");
        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (!token)
            {
                fprintf(stderr, "L%d: Invalid command\n", line_number);
                free_stack(stack);
                fclose(ma_file);
                exit(EXIT_FAILURE);
            }
            if (!is_numeric(token))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free_stack(stack);
                fclose(ma_file);
                exit(EXIT_FAILURE);
            }

            value = atoi(token);
            stack = ma_push(&stack, value);
        }
        else if (strcmp(token, "pall") == 0)
        {
            ma_pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: Unknown command: %s\n", line_number, token);
            free_stack(stack);
            fclose(ma_file);
            exit(EXIT_FAILURE);
        }
    }
    
    free_stack(stack);
    fclose(ma_file);
    return (EXIT_SUCCESS);
}