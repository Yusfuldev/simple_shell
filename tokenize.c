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

	if (buffer == NULL || *buffer == '\0')
		return (NULL);
	buf_cp = my_strdup(buffer);
	if (!buf_cp)
	{
		perror("strdup");
		free(buffer);
		return (NULL);
	}
	rm_spaces(buf_cp);
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
	for (i = 0; i < num_toks && token != NULL; i++)
	{
		args[i] = my_strdup(token);
		if (!args[i])
		{
			while (i > 0)
				free(args[--i]);
			free(args);
			free(buf_cp);
			free(buffer);
			return (NULL);
		}
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;

	free(buf_cp);
	return (args);
}

/**
 * rm_spaces- removes trailing spaces from buffer.
 * @p: buffer to remove space from
 * Return: nothing
 */
void rm_spaces(char *p)
{
	char *e = NULL;

	if (p == NULL || *p == '\0')
		return;

	e = p;	/* remove trailing spaces */
	while (*e != '\0')
		e++;
	if (*e == ' ')
	{
		while (*e == ' ')
			e--;
		*(e + 1) = '\0';
	}
}
