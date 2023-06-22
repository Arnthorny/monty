#include "monty.h"

/**
 * extract_word - Function to get "words" from given string
 * @s: String to extract words from
 * Return: First word seen or NULL if no words found.
 */

char *extract_word(char *s)
{
	char *word = NULL;
	int i = 0;

	while (s && s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (!word)
				word = &s[i];
		}
		else if (word)
		{
			s[i] = '\0';
			return (word);
		}
		i++;
	}

	return (word);
}

/**
 * is_number - Checks if a given string is a valid num
 * @str: Pointer to string
 * @num_p: Pointer to integer to return.
 * Return: Pointer to number or NULL if invalid number
 */

int *is_number(char *str, int *num_p)
{
	int i = 0;
	char c = '\0';

	if (!str)
		return (NULL);
	while (str && str[i])
	{
		c = str[i];
		if ((c >= '0' && c <= '9') || (i == 0 && (c == '+' || c == '-')))
			;
		else
			return (NULL);
		i++;
	}
	return (num_p);
}


/**
 * stack_len - Function to count elements in stack
 * @stack: Pointer to pointer of stack's head
 * Return: Number of elements in stack
 */

size_t stack_len(stack_t **stack)
{
	size_t count = 0;
	stack_t *head;

	head = *stack;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
