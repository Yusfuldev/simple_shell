#include "shell.h"
/**
 * builtin_handler- checks if a command is builtin and
 * calls the corresponding function.
 *
 * @args: command/argument to check for
 * Return: Nothing.
 */

int ch_dir(int ac, char **args)
{
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");

	if (ac == 1)
	{
		if (chdir(home) < 0)
			perror("chdir");
		update_dir();
		return (1);
	}

	if (strcmp(args[1], "-") == 0)
	{
		if (chdir(old_dir) < 0)
			perror("chdir");
		update_dir();
		return (1);
	}
	if (ac >= 2)
	{
		if (chdir(args[1]) < 0)
			perror("command");
		update_dir();
	}
	return (1);
}
void update_dir()
{
	char *pwd = NULL, *cwd = NULL;

	pwd = _getenv("PWD");
	cwd = getcwd(NULL, 0);
	setenv(pwd, cwd, 1);
}

int _exitt(int ac, char **args)
{
	int exit_status = 0;

	(void)ac;
	if (args[1] != NULL)
		exit_status = atoi(args[1]);
	exit(exit_status);
}
builtins_t built_ins[] = {
	{"cd", ch_dir},
	{"env", printenv},
	{"exit", _exitt},
	{NULL, NULL}
};

