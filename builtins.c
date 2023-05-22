#include "shell.h"
/**
 * ch-dir- changes the current working directory 
 * @ac: argument count
 * @args: command/path to change to
 * Return: 1 for loop to continue.
 */

int ch_dir(char **args)
{
	char *old_dir = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");

	if (args[1] == NULL)
	{
		printf("HOME");
		return (1);
	}
	if (strcmp(args[1], "-") == 0)
	{
		if (chdir(old_dir) < 0)
			perror("chdir");
		update_dir(pwd);
		return (1);
	}
	if (chdir(args[1]) < 0)
		perror("chdir");
	update_dir(pwd);

	return (1);
}

/**
 * update_dir- updates the pwd and oldpwd
 *
 * Return: nothing.
 */
void update_dir(char *pwd)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("OLDPWD", pwd, 1);
	setenv("PWD", cwd, 1);
	free(cwd);
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
 * 
 * contains list of commands to be carried out by Pp.
 */
builtins_t built_ins[] = {
	{"cd", ch_dir},
	{"env", printenv},
	{"exit", _exitt},
	{NULL, NULL}
};

