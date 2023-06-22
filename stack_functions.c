#include "monty.h"
/**
 * add_elem - Function to add element to stack
 * @head: Pointer to Pointer of stack's head
 * @n: Element's data
 * Return: Pointer to new element or NULL if failed
 */

stack_t *add_elem(stack_t **head, int n)
{
	stack_t *elem = NULL;

	if (!head)
		return (NULL);

	elem = malloc(sizeof(stack_t));
	if (!elem)
		return (NULL);

	elem->prev = NULL;
	if (*head)
		(*head)->prev = elem;
	elem->next = *head;
	(*head) = elem;
	(*head)->n = n;

	return (elem);
}
