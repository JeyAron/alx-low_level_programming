#include "main.h"

/**
 * _isdigit - check if character is a digit
 * @c: number to be checked
 * Return: 1 for a charscter that will be a digit or 0 for otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
	return (1);
	}
	return (0);
}
