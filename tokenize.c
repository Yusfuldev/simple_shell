#include "shell.h"
/**
 * tokenize- tokenize the command entered by user.
 * @buffer: buffer to tokenize.
 * Return: array of tokenized commands.
 */
char **tokenize(char *buffer)
{
	int num_toks = 0, i = 0;
	char *token = NULL, *buf_cp = NULL, **args = NULL;
	char *delim = " ";

	buf_cp = strdup(buffer);
	if (!buf_cp)
	{
		perror("Error: strdup");
		free(buffer);
		return (NULL);
	}
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
	for (; i <= num_toks && token != NULL; i++)
	{
		args[i] = strdup(token);
		printf("token: %s", args[i]);
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}
