#include "monty.h"
vars_t *element;
void execute_cmd(stack_t *stack);

/**
 * main - Entry point
 * @argc: Size of arguments
 * @argv: array of args
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t n = 0;
	vars_t temp = {NULL, NULL, NULL, NULL, 1, NULL};

	element = &temp;
	element->fname = argv[1];
	if (argc != 2)
	{
		print_error(1);
	}

	element->fp = fopen(element->fname, "r");
	if (element->fp == NULL)
	{
		print_error(2);
	}

	for (; getline(&(element->buf), &n, element->fp) != EOF; element->ln++)
	{
		element->tokened = malloc(sizeof(char *) * 2);
		if (!element->tokened)
			print_error(3);
		tokenize(element->buf);
		execute_cmd(stack);
		free_buffer();
		free_token();
	}
	free_buffer();
	free_token();
	fclose(element->fp);
	return (0);
}

/**
 * execute_cmd - Executes commands
 * @stack: Head of the stack
 * Return: None
 */
void execute_cmd(stack_t *stack)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};
	int i = 0;

	if (element->tokened[0] == NULL)
		return;
	if (element->tokened[0][0] == '#')
		return;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(element->tokened[0], opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&stack, element->ln);
			break;
		}
	}
	if (opcodes[i].opcode == NULL)
		print_error(4);
}
