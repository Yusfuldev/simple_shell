#include "shell.h"
/**
 * execute- executes th commands entered by user
 * @args: commands to ecxecute
 * @ac: number of arguments
 * Return: 1 to main to continue loop
 */

int execute(int ac, char **args, char *path)
{
	int i = 0;
/*	char *command = NULL;*/
	char *message = NULL;
	builtins_t *built_ins;

	built_ins = get_builtins();
	while (built_ins[i].name != NULL)
	{
		if (my_strcmp(built_ins[i].name, args[0]) == 0)
		{
			return (built_ins[i].func(args));
		}
		i++;
	}
	/**
	if ((_strstr(args[0], "/")) == NULL)
	{
		command = path_handler(args);*/
		if (path == NULL)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, args[0], my_strlen(args[0]));
			message = " : not found\n";
			write(STDERR_FILENO, message, my_strlen(message));
			return (1);
		}
	(void)ac;
	return (process(path, args));
}
/**
 * process- creates a process.
 * @command: command to execute
 * @args: arguments
 * Return: 1
 */
int process(char *command, char **args)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: fork");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, environ) < 0)
			perror("./hsh");
		exit(EXIT_SUCCESS);
	}
	wait(&status);
	return (1);
}
