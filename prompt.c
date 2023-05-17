#include "shell.h"
void _prompt(int argc, char **argv)
{
	char *command = NULL;
	int i = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}
		command = get_cmd();
		if (command != NULL)
		{
			argv = tokenize(command);
			execute(argc, argv);
			while (argv[i])
			{
				free(argv[i]);
				i++;
			}
			free(argv);
		}
		continue;
		free(command);
	}
}
