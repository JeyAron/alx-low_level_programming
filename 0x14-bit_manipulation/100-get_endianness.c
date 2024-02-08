#include "main.h"

/**
 * get_endianness - checks endianness
 * Return: if big endian then 0, if little endian then 1
 */

int get_endianness(void)
{
	int x;
	char *y;

	y = (char *)&x;
	x = 1;
	return (*y);
}
