#include "shell.h"
/**
 * _exitt - exits the shell with status.
 * @args: arguments
 * Return: exit status.
 */
int _exitt(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = atoi(args[1]);
	exit(exit_status);
}
