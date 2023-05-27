#include "shell.h"
/**
 * _setenv- updates or creates an environment variable.
 * @name: name of env
 * @value: value of env
 * Return: 1 for the loop to continue.
 */
int _setenv(char *name, char *value)
{
	int n = 0;
	size_t name_len = 0, env_len = 0, val_len = 0;
	char *new_env = NULL, **aux = NULL, **env = NULL;

	name_len = my_strlen(name);
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
	aux = environ;
	while (aux[n] != NULL)
	{
		if (my_strncmp(aux[n], name, name_len) == 0 && aux[n][name_len] == '=')
		{
			aux[n] = new_env;
			return (0);
		}
		n++;
	}
	env = _realloc(aux, (n + 2) * sizeof(char *));
	if (!env)
	{
		free(new_env);
		return (-1);
	}
	env[n] = new_env;
	env[n + 1] = NULL;
	environ = env;
	return (0);
}

