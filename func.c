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
    int start = 0, end = strlen(str) - 1;
    int i;
	char *trimmed_str;

    while (isspace((unsigned char)str[start]))
        start++;

    while ((end >= start) && isspace((unsigned char)str[end]))
        end--;

    trimmed_str = (char *)malloc((end - start + 2) * sizeof(char));
    if (trimmed_str == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed in trim function\n");
        exit(EXIT_FAILURE);
    }

    for (i = start; i <= end; i++)
    {
        trimmed_str[i - start] = str[i];
    }
    trimmed_str[end - start + 1] = '\0';

    return trimmed_str;
}

/**
 * is_numeric - checks if a string is a number
 * @str: string
 * Return: 1 if string is a number, 0 otherwise
 */
int is_numeric(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[i] == '-' || str[i] == '+')
		i++; /* Skip the optional sign */

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}