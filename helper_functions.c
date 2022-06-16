#include "monty.h"
#include <string.h>
#include <stdlib.h>

char *_strdup(char *s)
{
	size_t len, i;
	char *str2;

	len = strlen(s);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
	return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
	str2[i] = s[i];
	}

	return (str2);

}

/**
 * tokenize - Tokenize buffer
 * @buf: Line from our file
 * Return: None
 */
void tokenize(char *buf)
{
	char *token;
	char *delim;
	int i;

	element->tokened[0] = NULL;
	element->tokened[1] = NULL;
	delim = " \n";
	token = strtok(buf, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		element->tokened[i] = _strdup(token);
		if (!element->tokened[i])
		{
			print_error(3);
		}
		token = strtok(NULL, delim);
	}
}

/**
 * free_buffer - free getline buffer
 * Return: void
 */
void free_buffer(void)
{
	if (element->buf != NULL)
	{
		free(element->buf);
		element->buf = NULL;
	}
}
/**
  * free_token - Frees malloc'd tokens
  * Return: Nothing, void
  */
void free_token(void)
{
	if (element->tokened != NULL)
	{
		if (element->tokened[0] != NULL)
			free(element->tokened[0]);
		if (element->tokened[1] != NULL)
			free(element->tokened[1]);
		free(element->tokened);
	}
	element->tokened = NULL;
}
