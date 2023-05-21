#include "shell.h"

/**
 * printenv - prints all environment variables
 *
 * Return: nothing.
 */

int printenv(char **args)
{
	char **k = environ;
	int i = 0;

	(void)args;
	while (k[i])
	{
		write(STDOUT_FILENO, k[i], strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
