#include "shell.h"
/**
 * _setenv- updates or create an environment variable.
 * @nsrgs: arguments
 * Return: 0 or -1 on error.
 */

int _setenv(char **args)
{
	char *name = args[1];
	int i = 0;
	char *value = args[2];
	size_t name_len = 0, env_len = 0, val_len = 0;
	char *new_env = NULL;

	if (!name || !value)
	{
		perror("setenv");
		return (1);
	}

	name_len = strlen(name);        /* create new_env */
	val_len = strlen(value);
	env_len = name_len + val_len + 2;

	new_env = malloc(env_len * sizeof(char *));
	if (!new_env)
	{
		perror("setenv");
		return (1);
	}
	strcpy(new_env, name);
	strcat(new_env, "=");
	strcat(new_env, value);
	strcat(new_env, "\0");

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			free(environ[i]);
			environ[i] = new_env;
			return (1);
		}
		i++;
	}
	environ[i] = new_env;
	environ[i + 1] = '\0';
	return (1);
}
