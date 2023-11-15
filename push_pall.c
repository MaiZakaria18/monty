#include "monty.h"

/**
* is_numeric - Checks if a string represents a numeric value and,converts it.
* @str: The input string to be checked and converted.
* @value: Pointer to store the converted value.
* Return: 1 if the string is numeric and conversion is successful, 0 otherwise.
*/
int is_numeric(const char *str, int *value)
{
	char *endptr;
        *value = strtol(str, &endptr, 10);
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	return (*endptr == '\0' || isspace((unsigned char)*endptr));
}

/**
* create_node - Creates a new node with a given value and adds it to the stack.
* @stack: Double pointer to the top of the stack.
* @value: The value to be stored in the new node.
* Return: 1 if successful, 0 otherwise.
*/
int create_node(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		return (0);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
	return (1);
}

/**
* push - Handles the push opcode, pushing an element onto the stack.
* @stack: Double pointer to the top of the stack.
* @line: The line number in the input file.
*/
void push(stack_t **stack, unsigned int line)
{
	int value;

	if (val.arg == NULL || !is_numeric(val.arg, &value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(val.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (!create_node(stack, value))
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(val.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
* pall - Prints all the values on the stack, starting from the top.
* @stack: Pointer to the top of the stack.
* @line: The line number in the input file.
*/
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	(void)line;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
