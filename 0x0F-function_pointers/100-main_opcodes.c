#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints opcodes of program
 * @a: address of main function
 * @bytes: bytes to print
 * Return: void
 */

void print_opcodes(char *a, int bytes)
{
	int index;

	for (index = 0; index < bytes; index++)
	{
	printf("%.2hhx", a[index]);
	if (index < bytes - 1)
	printf(" ");
	}
	printf("\n");
}

/**
 * main - prints the opcodes of itself
 * @argv: array of pointers to the argmument
 * @argc: number of arguments supplied to the program
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int bytes;

	if (argc != 2)
	{
	printf("Error\n");
	exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
	printf("Error\n");
	exit(2);
	}

	print_opcodes((char *)&main, bytes);
	return (0);
}
