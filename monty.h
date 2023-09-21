#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <ctype.h>

#define LIMIT_STACK 1000
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_struct - Global buffers.
 * @cmdlist: Tokenized read buffer.
 * @cmdtoken: Tokenize each token from previous split based on spaces.
 * @argv: Arguments from command line.
 *
 * Description: - Buffers used globally throughout files.
 */
typedef struct bfstruct
{
        unsigned int num_lines;
	char *cmdlist[100];
	char *cmdtoken[100];
	char **argv;
} bfstruct;
extern bfstruct buf;
/*opcodes*/
void ma_pall(stack_t **stack, unsigned int line_number);
stack_t *ma_push(stack_t **stack, unsigned int line_number);

/*functions*/
FILE *open_file(char *filename, char *mode);
void free_stack(stack_t *stack);
bool is_numeric(const char *str);
void trim(char *str);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
