#include "monty.h"

/**
  * nop - doesn’t do anything
  * @stack: ptr to the top of the stack
  * @line_number: the line number of the command being execute
  * Return: void
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
  * pint - prints the value at the top of the stack, followed by a new line
  * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
  * Return: nothing, void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = element->head;
	(void) stack;
	(void) line_number;

	if (element->head == NULL)
		print_error(6);
	while (head->next)
	{
		head = head->next;
	}
	printf("%d\n", head->n);
}
