#include "monty.h"
bfstruct buf;

int main (int argc, char *argv[])
{
    char limit[LIMIT_STACK], *token;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    buf.argv = argv;
    
    buf.mafile = open_file(buf.argv[1], "r");
    if (!buf.mafile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", buf.argv[1]);
        exit(EXIT_FAILURE);
    }
    
    while (fgets(limit, LIMIT_STACK, buf.mafile))
    {
        buf.num_lines++;
        trim(limit);
        if (strlen(limit) < 3 || limit[0] == '#')
        {
            fprintf(stderr, "L%d: ignoring empty line\n", buf.num_lines);
            continue;
        }
        token = strtok(limit, " \t\n");
        if (!token)
            continue;
        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (!token || !is_numeric(token))
            {
                fprintf(stderr, "L%d: not integer\n", buf.num_lines);
                free_stack(buf.first);
                fclose(buf.mafile);
                fprintf(stderr, "L%d: usage: push integer\n", buf.num_lines);
                exit(EXIT_FAILURE);
            }
            else
                ma_push(&buf.first, atoi(token));
        }
        else if (strcmp(token, "pall") == 0)
        {
            ma_pall(&buf.first, buf.num_lines);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", buf.num_lines, token);
            if (buf.first)
                free_stack(buf.first);
            fclose(buf.mafile);
            exit(EXIT_FAILURE);
        }
    }

    free_stack(buf.first);
    fclose(buf.mafile);
    return (EXIT_SUCCESS);
}