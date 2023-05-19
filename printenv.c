#include "shell.h"

/**
 * printenv - prints all environment variables
 *
 * Return: nothing.
 */

void printenv(void)
{
	char **k = environ;
	int i = 0;

	while (k[i])
	{
		write(STDOUT_FILENO, k[i], strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
