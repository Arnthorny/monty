#include "monty.h"

/**
 * dov_func - Function to divides the  top two elements of the stack
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
