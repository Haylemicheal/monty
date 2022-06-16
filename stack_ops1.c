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
