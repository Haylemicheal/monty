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

/**
  * pop - removes the top element of the stack
  * @stack: ptr to the top of the stack
  * @line_number: the line number of the command being execute
  * Return: nothing, void
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = element->head;
	stack_t *temp;

	(void) stack;
	(void) line_number;

	temp = malloc(sizeof(stack_t));
	if (!temp)
		print_error(3);
	if (element->head == NULL)
		print_error(7);
	while (traverse->next)
		traverse = traverse->next;

	if (!traverse->prev)
	{
		traverse = NULL;
	}
	else
	{
		temp = traverse;
		traverse = traverse->prev;
		traverse->next = temp->next;
		free(temp);
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = element->head;
	int val = 0;

	(void) stack;
	(void) line_number;
	if (temp == NULL || temp->next == NULL)
	{
		print_error(8);
	}
	while (temp->next->next)
	{
		temp = temp->next;
	}
	val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = val;
}
