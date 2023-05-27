#include "shell.h"

/**
 * printenv - prints all environment variables
 * Return: nothing.
 */

int printenv(void)
{
	char **k = NULL;
	int i = 0;

	k = environ;
	while (k[i])
	{
		write(STDOUT_FILENO, k[i], my_strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

