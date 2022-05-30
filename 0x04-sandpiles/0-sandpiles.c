#include "sandpiles.h"
/**
 * print_grid - prints the grid
 * @grid: grid to print.
 * Return: nothing
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}
/**
 * is_stable - checks if the sandpile is stable
 * @grid: grid to check
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * sandpiles_simple_sum - adds sandpiles without toppling
 * @grid1: grid1
 * @grid2: grid2
 * Return: nothing
 */
void sandpiles_simple_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, c = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			c = grid1[x][y] + grid2[x][y];
			grid2[x][y] = c;
			grid1[x][y] = c;
		}
	}
}
/**
 * sandpiles_sum - with toppling
 * @grid1: grid1
 * @grid2: grid2
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	sandpiles_simple_sum(grid1, grid2);

	while (!(is_stable(grid1)))
	{
		printf("=\n");
		print_grid(grid1);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (grid1[x][y] > 3)
					grid1[x][y] -= 4;
				if ((x > 0) && (grid2[x - 1][y] > 3))
					grid1[x][y] += 1;
				if ((x < 2) && (grid2[x + 1][y] > 3))
					grid1[x][y] += 1;
				if ((y > 0) && (grid2[x][y - 1] > 3))
					grid1[x][y] += 1;
				if ((y < 2) && (grid2[x][y + 1] > 3))
					grid1[x][y] += 1;
			}
		}
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
				grid2[x][y] = grid1[x][y];
		}
	}
}
