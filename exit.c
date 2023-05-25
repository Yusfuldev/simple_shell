#include "shell.h"
/**
 * _exitt - exits the shell with status.
 * @args: arguments
 * Return: exit status.
 */
int _exitt(char **args)
{
	int exit_status = 0;

	if (args[1] == NULL)
		exit(EXIT_SUCCESS);
	exit_status = my_atoi(args[1]);
	exit(exit_status);
}

/**
 * my_atoi - a custom function that converts a string to integer
 *@s: input string
 *
 *Return: 0 always
 */
int my_atoi(const char *s)
{
	int sign = 1, i = 0;
	long result = 0;

	if (s == NULL)
		return (0);

	while (isspace((unsigned char)s[i]))
	{
		i++;
	}

	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}

	while (isdigit((unsigned char)s[i]))
	{
		result = result * 10 + (s[i] - '0');

		if (result * sign > INT_MAX)
		{
			return (INT_MAX);
		}
		if (result * sign < INT_MIN)
		{
			return (INT_MIN);
		}
		i++;

	}
	return ((int)(result * sign));
}
