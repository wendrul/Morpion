#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"
int	check_solution(char *grid, char player);

int	playagain()
{
	char replay;

	scanf("%c", &replay);
	while (1)
	{
		if (replay == 'Y' || replay == 'y')
			return (1);
		if (replay == 'N' || replay == 'n')
			return (0);
		printf ("Repondez 'y' (yes) ou 'n' (no)\n\n");
		scanf("%c", &replay);
	}
}

int	show_winner(char player)
{
	printf("Le joueur %c est gagnant! En meme temps la competition etait inexistante...\n\n", player);
	printf("Voulez vous relancer une partie afin de reafirmer votre dominance? Ou peut etre pour affronter un autre joueur? En esperant que celui-ci se montre au moins competant (Y/n)\n\n");
	return (playagain());
}

void	play_turn(char turn_player, char *grid, char other_player)
{
	int turnend;
	int place;

	printf("Au tour de %c, choisissez sagement\n\n", turn_player);
	turnend = 0;
	while (!turnend)
	{
		place = 0;
		scanf("%d", &place);
		if (place && place <= 9 && place >= 1)
		{
			place -= 1;
			if (grid[place] == turn_player)
				printf("En voila une idee interessante, doubler le pouvoir en y jouant deux fois! On y pensera pour Morpion 2.7.5\n");
			if (grid[place] == other_player)
				printf("Un emplacement ideal en effet... Malheureusement %c y a pense avant! On commence a voir qui est le plus intelligent des deux...\n", other_player);
			if (grid[place] == ' ')
			{
				printf("Un choix previsible, joueur suivant!\n\n");
				grid[place] = turn_player;
				turnend = 1;
			}
		}
		else
		{
			printf("Choissisez une case entre 1 et 9\n");
			place = 0;
			scanf("%d", &place);
		}	
	}
}

int	launch_game(char *grid, char p1, char p2)
{
	int turn;

	turn = 0;
	while(turn < 9)
	{
		print_grid(grid);
		if (check_solution(grid, p1))
			return (show_winner(p1));
		if (check_solution(grid, p2))
			return (show_winner(p2));
		if (turn % 2 == 0)
			play_turn(p1, grid, p2);
		else
			play_turn(p2, grid, p1);
		turn++;
	}
	printf("Alors qui est le gagnant? Et bien c'est personne! Voila vous avez tout decouvert sur ce jeu un peu simple. Voulez vous rejouer au risque de vous ennuyer d'avantage? (Y/n)\n");
	return (playagain());
}


