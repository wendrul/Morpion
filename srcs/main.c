#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int launch_game(char *grid, char p1, char p2);


void	tuto()
{
	printf ("Chacun votre tour, tapez la case ou vous voulez jouer selon le tableau suivant\n");
	printf("\e[92m");
	print_grid("123456789");
	printf("\e[0m");
	printf("\n\n");
}

int	main()
{
	int playagain;	

	srand(time(NULL));	
	tuto();
	playagain = 1;
	while (playagain)
	{
		char grid[] = "         ";
		playagain = launch_game(grid, 'O', 'X');
	}
	return (0);
}
