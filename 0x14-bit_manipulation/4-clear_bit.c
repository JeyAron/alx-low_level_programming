#include <stdlib.h>
#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at particular index
 * @n: parameter
 * @index: index
 * Return: if success 1, if error occurs -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
	return (-1);
	*n &= ~(1 << index);
	return (1);
}
