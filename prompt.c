#include "shell.h"

/**
 *_prompt - print the prompt
 *@argc: argument counts
 *@argv: argument vector
 *
 *Return: nothing
*/

void _prompt(int argc, char **argv)
{
	char *input = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}
		input = read_input();
		if (input != NULL)
		{
			argv = tokenize(input);
			execute(argc, argv);

			free_args(argv);
		}
		continue;
		free(input);
	}
}
