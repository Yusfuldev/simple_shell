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
 * get_builtins- initialise an array of structs.
 *
 * Return: struct pointer to the initialised array.
 */
builtins_t *get_builtins(void)
{
	builtins_t *ptr;

	builtins_t built_ins[] = {
		{"cd", ch_dir},
		{"env", printenv},
		{"exit", _exitt},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	ptr = built_ins;
	return (ptr);
}
