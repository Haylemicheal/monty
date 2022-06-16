#include "monty.h"

/**
 * print_error - Prints an error
 * @err_num: Error number
 * Return: None
 */
void print_error(int err_num)
{
	char *val = "";

	if (err_num == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (err_num == 2)
	{
		val = element->fname;
		fprintf(stderr, "Error: Can't open file %s\n", val);
	}
	else if (err_num == 3)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (err_num == 4)
	{
		val = element->tokened[0];
		fprintf(stderr, "L%d: unknown instruction %s\n", element->ln, val);
	}
	exit(EXIT_FAILURE);
}
