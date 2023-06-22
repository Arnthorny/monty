#include "monty.h"
prog_t *prog = NULL;

/**
 * main - The main function accepts the arguments
 * @argc: Argument count
 * @argv: Array of pointers
 * Return: EXIT_SUCCESS or EXIT_FAILURE if error
 */
int main(int argc, char *argv[])
{
	char *file;
	FILE *fp;
	stack_t *stack = NULL;
	prog_t prog_str = {NULL, NULL, NULL, NULL, 0, NULL};

	prog = &prog_str;
	if (argc != 2)
	{
		print_error(0, 1, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	file = argv[1];
	fp = fopen(file, "r");
	if (!fp)
	{
		print_error(0, 2, "Error: Can't open file ", file);
		exit(EXIT_FAILURE);
	}
	prog->fp = fp;
	prog->stack = &stack;
	handle_file(prog);
	free_prog(prog);

	return (EXIT_SUCCESS);
}
