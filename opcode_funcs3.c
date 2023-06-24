#include "monty.h"

/**
 * div_func - Function to divides the  top two elements of the stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void div_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	int division;

	if (lStack < 2)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": can't div, stack too short");
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": division by zero");
		exit(EXIT_FAILURE);

	}
	division = (*stack)->next->n / (*stack)->n;
	pop_func(stack, l_num);

	(*stack)->n = division;
}

/**
 * pchar_func - Function to print char(n) of head of stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void pchar_func(stack_t **stack, unsigned int l_num)
{
	if (!*stack || !stack)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num, ": can't pchar, stack empty");
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num, ": can't pchar, value out of range");
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr_func - Function to print char(n) of head of stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void pstr_func(stack_t **stack, UNUSED unsigned int l_num)
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
