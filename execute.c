#include "shell.h"
/**
 * execute- executes th commands entered by user
 * @args: commands to ecxecute
 * @ac: number of arguments
 * Return: 1 to main to continue loop
 */

int execute(int ac, char **args)
{
	int status = 0, exit_status = 0;
/*	char *command = NULL;*/
	pid_t child_pid;
/*	char *message;*/

	/*if (strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}*/
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			exit_status = atoi(args[1]);
		}
		else
		{
			exit_status = 0;
		}
		exit(exit_status);
	}
/*	command = path_handler(args);
	if (command == NULL)
	{
		write(STDOUT_FILENO, args[0], strlen(args[0]));
		message = ": not found\n";
		write(STDERR_FILENO, message, strlen(message));
		return (1);
	}*/
	(void)ac;
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: fork");
		fflush(stderr);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(/*command*/args[0], args, environ) < 0)
		{
			perror("./hsh");
			fflush(stderr);
		}
		exit(EXIT_FAILURE);
	}
	wait(&status);
	return (1);
}
