#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at particular index.
 * @n: number to set
 * @index: index at which to set bit
 * Return: if success 1, if an error occurred -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int setbit;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	setbit = 1 << index;
	*n = *n | setbit;
	return (1);
}
