#include "monty.h"

/**
 * print_error - Function to print error messages
 * @n: Nummber of strings to print
 * @is_line: 1 if error is a line error else 0
 */

void print_error(int is_line, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0, line_num;
	char *str;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		if (is_line && i == 1)
		{
			line_num = va_arg(args, int);
			fprintf(stderr, "%d", line_num);
		}
		else
		{
			str = va_arg(args, char *);
			fprintf(stderr, "%s", str);
		}
	}
	fprintf(stderr, "\n");
	va_end(args);
}
