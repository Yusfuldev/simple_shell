#include "shell.h"
void rm_spaces(char *p);
/**
 * tokenize- tokenize the command entered by user.
 * @buffer: buffer to tokenize.
 * @delim: delimeter.
 * Return: array of tokenized commands.
 */
char **tokenize(char *buffer, char *delim)
{
	int num_toks = 0, i = 0;
	char *token = NULL, *buf_cp = NULL, **args = NULL;

	buf_cp = my_strdup(buffer);
	if (!buf_cp)
	{
		perror("strdup");
		free(buffer);
		return (NULL);
	}
	token = _strtok(buf_cp, delim);
	while (token)	/* get number of tokens*/
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
		args[i] = my_strdup(token);
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;
	free(buf_cp);
	return (args);
}
