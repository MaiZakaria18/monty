#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
/**
 * initialize - Handles initialization, checking command-line arguments,
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 */
void initialize(int argc, char *argv[])
{
/* Check for the correct number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
/* Open the input file for reading */
	val.file = fopen(argv[1], "r");
	if (val.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * parse_file - Reads each line from the input file, executes corresponding
 *              opcodes, and handles errors.
 * @stack: Pointer to the top of the stack.
 */
void parse_file(stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

/* Read each line from the input file */
	while (getline(&line, &len, val.file) != -1)
	{
		line_number++;
/* Execute the opcode and handle errors */
		if (execute(line, stack, line_number, val.file) == 0)
		{
			free(line);
			break;
		}
	}
	free(line);
}

/**
 * execute - Parses and executes the opcode from the input line.
 * @content: The input line content containing opcode and arguments.
 * @stack: Pointer to the top of the stack.
 * @line: The line number in the input file.
 * @file: Pointer to the input file.
 */
int execute(char *content, stack_t **stack, unsigned int line, FILE *file)
{
	return (parse_op(content, stack, line, file));

}

/**
 * close_input - Closes the input file and frees allocated memory.
 * @stack: Pointer to the top of the stack.
 */
void close_input(stack_t **stack)
{
/* Close the input file */
	fclose(val.file);

/* Free memory used by the stack and input line */
	free_stack(*stack);
	free(val.line);
}
/**
 * main - Entry point of the Monty interpreter program.
 *        Initializes the program, parses the input file, and performs cleanup.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: EXIT_SUCCESS on successful execution, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
/* Initialize program, checking command-line arguments, opening input file */
	initialize(argc, argv);
/* Parse the input file, execute opcodes, and handle errors */
	parse_file(&stack);
/* Clean up resources, close the input file, and free allocated memory */
	close_input(&stack);
/* Exit the program with the appropriate exit code */
	exit(EXIT_SUCCESS);
}
