#include "monty.h"

/**
 * add_stack_init - add a node at the beggining of a stack_t
 * Return: Address of new node or NULL if failed
 */
stack_t *add_stack_init(void)
{
	stack_t *temp = NULL;
	stack_t *head = element->head;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	temp->next = (head == NULL) ? NULL : head;
	temp->prev = NULL;
	if (head)
		head->prev = temp;
	element->head = temp;
	return (temp);
}
/**
  * add_stack_end - adds an element to the end of the stack (FIFO, queue only)
  * Return: address of new node or NULL if failed
  */
stack_t *add_stack_end(void)
{
	stack_t *temp = NULL;
	stack_t *head = element->head;
	stack_t *traverse;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	if (head == NULL)
	{
		free(temp);
		temp = add_stack_init();
	}
	else
	{
		traverse = head;
		while (traverse->next != NULL)
			traverse = traverse->next;
		temp->next = NULL;
		temp->prev = traverse;
		traverse->next = temp;
	}
	return (temp);
}

/**
 * push - pushes an element to the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the command being run
 *
 * Return: 0
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *pStack = NULL;
	char *temp;
	int i = 0, f = 0, negative = 0;

	(void) line_number;
	(void) stack;
	pStack = add_stack_end();
	temp = element->tokened[1];
	if (pStack == NULL)
		print_error(3);

	if (temp != NULL)
	{
		if (temp[0] == '-')
		{
			i++;
			f = 1;
			negative = 1;
		}
		while (temp[i] != '\0')
		{
			if (isdigit(temp[i]) == 0)
			{
				f = 1;
				break;
			}
			i++;
			f = 0;
		}
		if (f == 0)
		{
			if (negative == 1)
				temp = temp + 1;
			pStack->n = atoi(temp);
			if (negative == 1)
				pStack->n *= -1;
			return;
		}
	}
	print_error(5);
}


/**
 * pall -  prints all the values on the stack, starting from
 * the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the command being run
 *
 * Return: 0
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = element->head;

	(void) stack;
	(void) line_number;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}

}
