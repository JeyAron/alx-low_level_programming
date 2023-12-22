#include "main.h"

/**
 * print_diagonal - draws diagonal lines
 * @n: number of diagonal lines to print
 * Return: empty
 */

void print_diagonal(int n)
{
	int a, b;

	if (n <= 0)
	{
	_putchar('\n');
	}
	else
	{
	for (a = 0; a < n; a++)
	{
	for (b = 0; b < n; b++)
	{
	_putchar(32);
	}
	_putchar(92);
	_putchar('\n');
	}
	}
}
