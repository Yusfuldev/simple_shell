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
		write(STDOUT_FILENO, k[i], my_strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}


/**
 * _exitt- exits the shell with status.
 * @args: arguments
 * Returns: exit status.
 */
int _exitt(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = atoi(args[1]);
	exit(exit_status);
}

/**
 * buit_ins- array of struts of builtin commands
 * contains list of commands to be carried out by Pp.
 */
builtins_t built_ins[] = {
	{"cd", ch_dir},
	{"env", printenv},
	{"exit", _exitt},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{NULL, NULL}
};
