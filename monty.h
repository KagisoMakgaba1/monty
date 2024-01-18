#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
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
 * struct argument_s - hold variables
 * @stream: file that connects to the stream
 * @line: the line of text to read from
 * @instruction: a valid instruction from a line
 * @head: head/top of the stack (doubly linked lists of struct stack_s)
 * @line_number: for tracking current line number
 * @tokens: used to store tokens from line
 * @n_tokens; number of tokens created from line
 *
 */

typedef struct argument_s
{
	FILE *stream;
	char *line;
	instruction_t *instruction;
	stack_t *head;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
} arg_t;

extern arg_t *arguments;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

void initialize_args();
void malloc_fail(void);
void free_args(void);
void free_head(void);
void get_stream(char *fileName);
void get_stream_fail(char *fileName);
void free_stack(stack_t *head);
void tokenize(void);
void free_memory(void);
void get_instruction(void);
void invalid_instruction(void);
void close_stream(void);
void free_tokens(void);
void run_instruction(void);

#endif
