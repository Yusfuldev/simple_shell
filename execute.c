#include "shell.h"
/**
 * execute- executes th commands entered by user
 * @args: commands to ecxecute
 * @ac: number of arguments
 * Return: 1 to main to continue loop
 */

int execute(int ac, char **args, char **command)
{
	char *message = NULL;

	if (builtin_handler(args, command) == 0)
	{
	args[0] = path_handler(args);
	if (args[0] == NULL)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], my_strlen(args[0]));
		message = " : not found\n";
		write(STDERR_FILENO, message, my_strlen(message));
		return (1);
	}
	(void)ac;
	return (process(args));
	}
	return (1);
}

/**
 * process- creates a process.
 * @args: arguments
 * Return: 1
 */
int process(char **args)
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
		if ((status = execve(args[0], args, environ)) < 0)
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
	}

	return (1);
}
