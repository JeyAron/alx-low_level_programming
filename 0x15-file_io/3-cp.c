#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_IO_stat(int stat, int fd, char *filename, char mode);

/**
 * main - copies content of a file to another
 * @argc: argument count
 * @argv: argument passed
 * Return: on succes 1, otherwise exit
 */

int main(int argc, char *argv[])
{
	int arc, n_read = 1024, dest, wrote, close_arc, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR |S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
	exit(97);
	}
	arc = open(argv[1], O_RDONLY);
	check_IO_stat(arc, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(dest, -1, argv[2], 'W');
	while (n_read == 1024)
	{
	n_read = read(arc, buffer, sizeof(buffer));
	if (n_read == -1)
	check_IO_stat(-1, -1, argv[1], 'O');
	wrote = write(dest, buffer, n_read);
	if (wrote == -1)
	check_IO_stat(-1, -1, argv[2], 'W');
	}
	close_arc = close(arc);
	check_IO_stat(close_arc, arc, NULL,'C');
	close_dest = close(dest);
	check_IO_stat(close_dest, dest, NULL, 'C');
	return (0);
}

/**
 * check_IO_stat - checks if file can be opened or closed
 * @stat: descriptor of file to be opened
 * @filename: name of file
 * @mode: closing or opening
 * @fd: file descriptor
 * Return: void
 */

void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
	}
}
