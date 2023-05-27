#include "shell.h"
/**
 * _setenv- updates or create an environment variable.
 * @args: arguments
 * Return: 1 for loop to continue.
 */

int _setenv(char *name, char *value)
{
	int i = 0, n = 0;
	size_t name_len = 0, env_len = 0, val_len = 0;
	char *new_env = NULL, **aux = NULL;

	name_len = my_strlen(name);        /* create new_env */
	val_len = my_strlen(value);
	env_len = name_len + val_len + 2;
	new_env = malloc(env_len * sizeof(char));
	if (!new_env)
	{
		perror("setenv");
		return (1);
	}
	my_strcpy(new_env, name);
	my_strcat(new_env, "=");
	my_strcat(new_env, value);
	my_strcat(new_env, "\0");

	while (environ[i] != NULL)
		i++;
	aux = malloc(sizeof(char *) * (i + 1));
	if (!aux)
	{
		perror("_setenv");
		return (1);
	}
	while (n < i)
	{
		aux[n] = environ[n];
		n++;
	}

	n = 0;
	while (environ[n] != NULL)
	{
		if (my_strncmp(environ[n], name, name_len) == 0
&& environ[n][name_len] == '=')
		{
			free(aux[n]);
			aux[n] = new_env;
			environ = aux;
			return (1);
		}
		n++;
	}
	aux[i] = new_env;
	aux[i + 1] = NULL;
	environ = aux;
	return (1);
}
