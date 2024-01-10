#include "main.h"
#include <stdio.h>

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: number whose square root is to be calculated
 * Return: the natural square root
 */

int _sqrt(int n, int i);
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - calculates the natural square
 * @n: number whose square root is to be calculated
 * @i: iterate number
 * Return: the natural square root
 */

int _sqrt(int n, int i)
{
	int sqrt = i * i;

	if (sqrt > n)
	return (-1);

	if (sqrt == n)
	return (i);

	return(_sqrt(n, i + 1));
}
