#include "monty.h"

/**
 * nop_func - Function that does nothing
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void nop_func(UNUSED stack_t **stack, UNUSED unsigned int l_num)
{
	;
}
/**
 * add_func - Function to add the top two elements of the stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void add_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	int addition;

	if (lStack < 2)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": can't add, stack too short");
		exit(EXIT_FAILURE);
	}

	addition = (*stack)->n + (*stack)->next->n;
	pop_func(stack, l_num);

	(*stack)->n = addition;
}
