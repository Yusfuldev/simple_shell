#include "shell.h"

/**
 *_prompt - print the prompt
 *@argc: argument counts
 *@argv: argument vector
 *
 *Return: nothing
*/

void _prompt(int argc, __attribute__((unused))char **argv, int mode)
{
	int i = 0;
	char *input = NULL;
	char **command = NULL;
	char **result = NULL;
	while (1)
	{
		if (mode)
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}

		input = read_input();
		if (input != NULL)
		{
			command = tokenize(input, ";");
			/*free(input);*/
			input = NULL;
			i = 0;
			while (command[i] != NULL)
			{
				result = tokenize(command[i], " ");
				execute(argc, result, command);
				i++;
			}
			free_args(result);
			free(command);
			/*free(result);*/
			result = NULL;
		}
		continue;
	}
}
