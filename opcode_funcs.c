#include "monty.h"

/**
 * push_func - Function to handle the push opcode
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */

void push_func(stack_t **stack, unsigned int l_num)
{
	int num_to_push;
	stack_t *elem = NULL;

	if (!is_number(prog->instr, &num_to_push))
	{
		print_error(1, 3, "L", l_num, ": usage: push integer");
		free_prog(prog);
		exit(EXIT_FAILURE);
	}
	num_to_push = atoi(prog->instr);

	elem = add_elem(stack, num_to_push);
	if (!elem)
	{
		free_prog(prog);
		print_error(0, 1, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}


/**
 * pall_func - Function to handle the pall opcode
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */

void pall_func(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
