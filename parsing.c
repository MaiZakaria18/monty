#include "monty.h"
/**
* find_opcode - Finds and executes opcode.
* @op: The opcode to be searched and executed.
* @stack: Double pointer to the top of the stack.
* @line: The line number in the input file.
* @file: Pointer to the input file.
*/
void find_opcode(char *op, stack_t **stack, unsigned int line, FILE *file)
{
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int x = 0;

/* Search for the opcode in the instruction set */
	while (opc[x].opcode && op)
	{
		if (strcmp(op, opc[x].opcode) == 0)
		{
/* Execute the corresponding function for the found opcode */
			opc[x].f(stack, line);
			return;
		}
		x++;
	}
/* Handle the case when the opcode is not found */
	if (op && opc[x].opcode == NULL)
	{
		unknown_er(line, op, file, stack);
	}
}

/**
* parse_op - Parses the opcode from the input content and executes it.
* @content: The input line content containing opcode and arguments.
* @stack: Double pointer to the top of the stack.
* @line: The line number in the input file.
* @file: Pointer to the input file.
* Return: 0 if the line is a comment, 1 otherwise.
*/
int parse_op(char *content, stack_t **stack, unsigned int line, FILE *file)
{
	char *op;
/* Tokenize the input content to extract the opcode */
	op = strtok(content, " \n\t");
/* Check for comment lines and ignore them */
	if (op && op[0] == '#')
		return (0);

/* Parse and execute the opcode */
	val.arg = strtok(NULL, " \n\t");
	find_opcode(op, stack, line, file);
	return (1);
}

/**
* unknown_er - Handles the error for an unknown opcode.
* @line: The line number in the input file.
* @op: The unknown opcode.
* @file: Pointer to the input file.
* @stack: Double pointer to the top of the stack.
*/
void unknown_er(unsigned int line, const char *op, FILE *file, stack_t **stack)
{
/* Print an error message for an unknown instruction and exit the program */
	fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
