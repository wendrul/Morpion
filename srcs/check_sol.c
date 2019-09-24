#include "affichage.h"
#include <stdio.h>

int	check_row(char *grid, int row, char piece)
{
	return (grid[row] == grid[row + 1] && grid[row] == grid[row + 2] && grid[row] == piece);
}

int	check_col(char *grid, int col, char piece)
{
	return (grid[col] == grid[col + 3 * 1] && grid[col] == grid[col + 2 * 3] && grid[col] == piece);
}

int	check_solution(char *grid, char piece)
{
	int diag2;
	int diag1;
	int cpt;

	cpt = 0;
	diag1 = grid[0] == grid[4] && grid[0] == grid[8] && grid[0] == piece;
	diag2 = grid[2] == grid[4] && grid[2] == grid[6] && grid[2] == piece;
	while (cpt < 3)
	{
		if (check_row(grid, cpt, piece) || check_col(grid, cpt, piece))
			return (1);
		cpt++;
	}
	return (diag1 || diag2);
}
