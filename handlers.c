#include "monty.h"

/**
 * get_cmd_fn - This function get the corresponding opcode function
 * @prog: Pointer to Program's Struct
 * Return: The function pointer or NULL if invalid opcode
 */

opcode_fn_t get_cmd_fn(prog_t *prog)
{
	instruction_t all_ops[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		/*
		 * {"swap", swap_func},
		 * {"add", add_func},
		 * {"nop", nop_func},
		 */
		{NULL, NULL}
	};
	int i = 0;

	while (all_ops[i].opcode)
	{
		if (strcmp(prog->opcode, all_ops[i].opcode) == 0)
			return (all_ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * handle_cmd - This function extracts lines from file
 * @prog: Pointer to Program's Struct
 * @op_fn: Opcode function to be executed
 */

void handle_cmd(prog_t *prog, opcode_fn_t op_fn)
{
	unsigned int l_num = prog->line_num;

	if (!op_fn)
	{
		print_error(1, 4, "L", l_num, ": unknown instruction ", prog->opcode);
		free_prog(prog);
		exit(EXIT_FAILURE);
	}
	else
		op_fn(prog->stack, prog->line_num);
}

/**
 * handle_file - This function extracts lines from file
 * @prog: Pointer to Program's Struct
 */

void handle_file(prog_t *prog)
{
	unsigned int line_num = 1;
	char *curr_line = NULL, *instr = NULL, *opcode = NULL;
	size_t n = 0;
	ssize_t char_count;

	do {
		errno = 0;
		char_count = getline(&curr_line, &n, prog->fp);
		prog->curr_line = curr_line;
		if (char_count == -1)
		{
			if (errno == ENOMEM)
			{
				free_prog(prog);
				print_error(0, 1, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			break;
		}
		opcode = extract_word(curr_line);
		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if ((curr_line + char_count) > (opcode + strlen(opcode)))
					instr = extract_word((opcode + strlen(opcode) + 1));

			}

			prog->instr = instr;
			prog->line_num = line_num;
			prog->opcode = opcode;
			handle_cmd(prog, get_cmd_fn(prog));
		}
		line_num++;
	} while (char_count != -1);
}
