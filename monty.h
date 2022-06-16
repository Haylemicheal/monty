#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
 * struct vars_s - Holds variables
 * @fname: String holding file name
 * @fp: File pointer
 * @tokened: Tokenized string from our file
 * @buf: Buffer of the line in the file
 * @ln: The read line number
 * @head: Head of the stack
 */
typedef struct vars_s
{
	char *fname;
	FILE *fp;
	char **tokened;
	char *buf;
	unsigned int ln;
	stack_t *head;
} vars_t;

extern vars_t *element;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

void print_error(int err_num);

void tokenize(char *buf);
void free_buffer(void);
void free_token(void);
#endif
