#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
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
 * struct - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct
{
	char *arg;
	FILE *file;
	char *line;
} val_t;
val_t val;
void initialize(int argc, char *argv[]);
void parse_file(stack_t **stack);
int execute(char *content, stack_t **stack, unsigned int line, FILE *file);
void close_input(stack_t **stack);
int main(int argc, char *argv[]);
void unknown_er(unsigned int line, const char *op, FILE *file, stack_t **stack);
int parse_op(char *content, stack_t **stack, unsigned int line, FILE *file);
void find_opcode(char *op, stack_t **stack, unsigned int line, FILE *file);
int is_numeric(const char *str, int *value);
int create_node(stack_t **stack, int value);
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void free_stack(stack_t *top);

#endif /* MONTY_H */

