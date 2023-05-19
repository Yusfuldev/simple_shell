#include "shell.h"
/**
 * _getline- reads an entire line from stream.
 * @lineptr: address of buffer containing text.
 * @n: size of buffer
 * Return: Number of bytes read or -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer = NULL;
	ssize_t nbytes = 0;
	size_t index = 0;
	char *new_buf = NULL;
	char ch;
	size_t bytes_read = 0;
	size_t buf_size = 0;

	if (!lineptr || !n || !stream)
		return (-1);
	buf_size = BUFSIZ;
	buffer = malloc(buf_size);
	while (1)
	{
		if (bytes_read >= (buf_size - 1))
		{
			buf_size += BUFSIZ;
			new_buf = realloc(buffer, buf_size);
			if (!new_buf)
				return (-1);
			buffer = new_buf;
		}
		nbytes = read(fileno(stream), &ch, 1);
		if (nbytes <= 0)
			return (-1);
		buffer[index] = ch;
		index++;
		bytes_read++;
		if (buffer[index - 1] == '\n')
			break;
	}
	buffer[index] = '\0';
	*lineptr = buffer;
	return (bytes_read);
}
