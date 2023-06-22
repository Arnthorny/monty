#include "monty.h"

/**
 * nop_func - Function that does nothing
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void nop_func(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
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

/**
 * sub_func - Function to subtract the top two elements of the stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void sub_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	int subtraction;

	if (lStack < 2)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": can't sub, stack too short");
		exit(EXIT_FAILURE);
	}

	subtraction = (*stack)->next->n - (*stack)->n;
	pop_func(stack, l_num);

	(*stack)->n = subtraction;
}

/**
 * mul_func - Function to muliply the top two elements of the stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void mul_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	int multiplication;

	if (lStack < 2)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": can't mul, stack too short");
		exit(EXIT_FAILURE);
	}

	multiplication = (*stack)->next->n * (*stack)->n;
	pop_func(stack, l_num);

	(*stack)->n = multiplication;
}

/**
 * mod_func - Function to modulo between top two elements of the stack
 * @stack: Pointer to pointer of stack's head
 * @l_num: Current Line Number
 */
void mod_func(stack_t **stack, unsigned int l_num)
{
	size_t lStack = stack_len(stack);
	int mod;

	if (lStack < 2)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": can't mod, stack too short");
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		free_prog(prog);
		print_error(1, 3, "L", l_num,  ": division by zero");
		exit(EXIT_FAILURE);

	}
	mod = (*stack)->next->n % (*stack)->n;
	pop_func(stack, l_num);

	(*stack)->n = mod;
}
