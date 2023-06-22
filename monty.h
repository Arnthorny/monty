#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#define UNUSED __attribute__((unused))

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct prog_s - Entire program structure and elements
 * @fp: File Pointer to file being read
 * @curr_line: Current Line being read
 * @opcode: String containing Current executing opcode
 * @instr: instruction for "push" opcode else NULL
 * @line_num: Current line number
 * @stack: Pointer to stack's head
 *
 * Description: Program Structure and its elements
 */
typedef struct prog_s
{
	FILE *fp;
	char *curr_line;
	char *opcode;
	char *instr;
	unsigned int line_num;
	stack_t **stack;
} prog_t;

extern prog_t *prog;
typedef void (*opcode_fn_t)(stack_t **stack, unsigned int line_number);

void pall_func(stack_t **stack, unsigned int l_num);
void push_func(stack_t **stack, unsigned int l_num);
void pop_func(stack_t **stack, unsigned int l_num);
void pint_func(stack_t **stack, unsigned int l_num);
void swap_func(stack_t **stack, unsigned int l_num);
void free_prog(prog_t *prog);
void sub_func(stack_t **stack, unsigned int l_num);
void div_func(stack_t **stack, unsigned int l_num);
void mul_func(stack_t **stack, unsigned int l_num);
void mod_func(stack_t **stack, unsigned int l_num);
void free_stack(stack_t *head);
stack_t *add_elem(stack_t **head, int n);
void print_error(int is_line, const unsigned int n, ...);
opcode_fn_t get_cmd_fn(prog_t *prog);
void handle_cmd(prog_t *prog, opcode_fn_t op_fn);
void handle_file(prog_t *prog);
char *extract_word(char *s);
int *is_number(char *str, int *num_p);
size_t stack_len(stack_t **stack);
void add_func(stack_t **stack, unsigned int l_num);
void nop_func(UNUSED stack_t **stack, UNUSED unsigned int l_num);
void rotl_func(stack_t **stack, unsigned int l_num);
void rotr_func(stack_t **stack, unsigned int l_num);


#endif /*_MONTY_H_*/
