#include "monty.h"

/**
 * open_file - opens a file
 * @filename: name of the file
 * Return: pointer to the file
 */
FILE *open_file(char *filename, char *mode)
{
    FILE *ma_file;

    ma_file = fopen(filename, mode);
    if (ma_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return (ma_file);

}
/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
 * trim - removes whitespace from the beginning and end of a string
 * @str: string
 * Return: void
 */
char *trim(char *str)
{
	while (*str)
    {
        if (*str == ' ' || *str == '\t' || *str == '\n'
            || *str == '\v' || *str == '\f' || *str == '\r')
            str++;
        else
            break;
    }
    return (str);
}
/**
 * is_numeric - checks if a string is a number
 * @str: string
 * Return: 1 if string is a number, 0 otherwise
 */
bool is_numeric(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (false);

	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit((unsigned char)str[i]))
			return (false);
		i++;
	}

	return (true);
}
