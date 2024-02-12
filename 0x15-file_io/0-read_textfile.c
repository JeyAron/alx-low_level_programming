#include "main.h"

/**
 * read_textfile - function that read text file and prints to POSIX standard
 * output
 * @filename: text to print
 * @letters: max number of letters printed
 * Return: number of letters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buff;

	if (!filename)
	return (0);
	fd = open(fiename, O_RDONLY);
	if (fd == -1)
	return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	return (0);
	nrd = read(fd, buff, letters);
	nwr = write(STDOUT_FILENO, buff, nrd);
	close(d);
	free(buff);
	return (nwr);
}
