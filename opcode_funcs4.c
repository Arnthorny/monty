#include "monty.h"

/**
 * rotl_func - Function to rotate the stack to the top
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 * Description: The top element of the stack becomes the last, and the second
 * top element of the stack becomes the first one
 */
void rotl_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	stack_t *current, *last, *tmp;

	if (lStack <= 1)
		return;
	else if (lStack == 2)
		swap_func(stack, l_num);

	else
	{
		current = (*stack);
		tmp = current;
		while (tmp)
		{
			if (tmp->next == NULL)
				last = tmp;
			tmp = tmp->next;
		}
		tmp = current->next;

		last->next = current;
		current->prev = last;
		current->next = NULL;
		tmp->prev = NULL;

		*stack = tmp;
	}

}


/**
 * rotr_func - Function to rotate the stack to the bottom
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 * Description: The last element of the stack becomes the top element.
 */
void rotr_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	stack_t *head, *last, *tmp;

	if (lStack <= 1)
		return;
	else if (lStack == 2)
		swap_func(stack, l_num);

	else
	{
		head = (*stack);
		tmp = head;
		while (tmp)
		{
			if (tmp->next == NULL)
				last = tmp;
			tmp = tmp->next;
		}
		tmp = last->prev;

		head->prev = last;
		last->next = head;
		last->prev = NULL;
		tmp->next = NULL;

		*stack = last;

	}

}
