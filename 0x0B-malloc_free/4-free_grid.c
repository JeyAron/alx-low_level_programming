#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees the grid
 * @grid: multidimensional array of integers
 * @height: height of grid
 * Return: no return
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
	free(grid[i]);
	}
	free(grid);
}
