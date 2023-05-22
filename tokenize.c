#include "shell.h"
/**
 * tokenize- tokenize the command entered by user.
 * @buffer: buffer to tokenize.
 * Return: array of tokenized commands.
 */
char **tokenize(char *buffer, char *delim)
{
	int num_toks = 0, i = 0;
	char *token = NULL, *buf_cp = NULL, **args = NULL;
	char *e = NULL;

	while(*buffer == ' ')	/* remove preceding spaces */
		buffer++;

	buf_cp = strdup(buffer);
	if (!buf_cp)
	{
		perror("strdup");
		free(buffer);
		return (NULL);
	}
	e = buf_cp;	/* remove trailing spaces */
	while (*e != '\0')
		e++;
	while (*e == ' ')
		e--;
	*(e + 1) = '\0';
	token = _strtok(buf_cp, delim);
	while (token != NULL)	/* get number of tokens*/
	{
		num_toks++;
		token = _strtok(NULL, delim);
	}

	args = malloc(sizeof(char *) * (num_toks + 1));
	if (!args)
	{
		perror("Error: malloc");
		free(buf_cp);
		free(buffer);
		return (NULL);
	}
	token = _strtok(buffer, delim);
	for (; i < num_toks && token != NULL; i++)
	{
		args[i] = strdup(token);
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;
	free(buf_cp);
	return (args);
}
