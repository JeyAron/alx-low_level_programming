#include "main.h"

/**
 * append_text_to_file - appends text at the end of file
 * @filename: name of file
 * @text_content: string to add to end of file
 * Return: if function fails -1, if file does not exist, -1, otherwise 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, rw, len = 0;

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	rw = write(fd, text_content, len);
	if (fd == -1 || rw == -1)
	return (-1);
	close(fd);
	return (1);
}
