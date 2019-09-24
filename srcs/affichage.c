#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define REPLIES_PATH "lines.txt"

void	print_grid(char *grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		printf(" %c | %c | %c \n", grid[i], grid[i + 1], grid[i + 2]);
		i += 3;
		if (i <= 6)
			printf("___|___|___\n");
	else
			printf("   |   |   \n");
	}
}
