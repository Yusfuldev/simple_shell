#include "shell.h"

/**
 * printenv - prints all environment variables
 * @args: arguments.
 * Return: nothing.
 */

int printenv(char **args)
{
	char **k = NULL;
	int i = 0;

	(void)args;
	k = environ;
	while (k[i])
	{
		write(STDOUT_FILENO, k[i], my_strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}


/**
 * built_ins - Array of structs for builtin commands.
 *
 * Description: This array stores a list of builtin commands and their
 * corresponding functions.
 * The commands can be executed by the parent process.
 */
builtins_t built_ins[] = {
	{"cd", ch_dir},
	{"env", printenv},
	{"exit", _exitt},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{NULL, NULL}
};
