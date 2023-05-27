#include "shell.h"
/**
 * _unsetenv- removes an environment variable from list
 * @name: name of env to unset.
 * Return: 0 or -1 on failure.
 */
int _unsetenv(char *name)
{
	int i = 0;
	size_t name_len = my_strlen(name);
	char **aux = NULL, **env = NULL;

	if (!name) /* invalid name */
	{
		perror("unsetenv");
		return (-1);
	}
	environ = env;
	while (env[i] != NULL)
	{
		if (my_strncmp(env[i], name, name_len) == 0
				&& env[i][name_len] == '=')
			i++;
		aux[i] = env[i];
		i++;
	}
	aux[i] = NULL;
	environ = aux;
	return (0);
}

