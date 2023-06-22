#include "monty.h"

/**
 * free_stack - Function to free up the stack
 * @head: Pointer to stack head
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * free_prog - Function to clean up program before exiting
 * @prog: Pointer to strucure for entire progam
 */

void free_prog(prog_t *prog)
{
	fclose(prog->fp);
	free(prog->curr_line);
	free_stack(*(prog->stack));
}

