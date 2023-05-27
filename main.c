#include "shell.h"
/**
 * main- Entry point of shell.
 * @argc: arguments count.
 * @argv: arguments vector.
 * Return: 0 otherwise negative integer.
 */

int main(int argc, char **argv)
{
	int mode = 0;

	if (isatty(STDIN_FILENO) == 1)
		mode = 1;
	errno = 0;

	_prompt(argc, argv, mode);
	return (0);
}
