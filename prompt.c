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
	int i = 0;
	char *input = NULL;
	char **command = NULL;
	char *path = NULL; 

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
			command = tokenize(input, ";");
			i = 0;
			while (command[i] != NULL)
			{
				argv = tokenize(command[i], " ");
				path = path_handler(argv);
				execute(argc, argv, path);
				free_args(argv);
				free(path);
				i++;
			}
			free_args(command);
		}
		free(input);
		continue;
	}
}
