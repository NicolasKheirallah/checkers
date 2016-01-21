
/*

Nicolas Kheirallah
This code explain what functions the player has

*/
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "bonus.h"

//This code checks what the user wants for special feature when reaching the end of the GameBoard
int bonus()
{
	int i;
	printf("Choose which choice you want :  1. Delete a oppponent  \n");
	scanf_s("%d", &i);

	if (i == 1) {
		printf("Delete oppponent !\n");
		return 1;
	}
	else
	{
		printf("Invalid choice , bonus lost!\n");
		return 0;
	}
}

//checks if the player is at the end of the GameBoard
int check_GameBoard_end(int player, int next_y)
{
	if (player == 1) {
		if (next_y == 8) {
			return 1;
		}
	}
	else if (player == 2) {
		if (next_y == 1) {
			return 1;
		}
	}
	return 0;
}

//Chooses which enemy on the GameBoard you can delete 
int delete_enemy(int player, int GameBoard[9][8])
{
	int x, y;
	printf("\n Enter the cordinate of the checker you want to remove :");
	scanf_s("%d %d", &x, &y);

	if (player == 1) {
		if (GameBoard[x - 1][y - 1] == 2) {

			GameBoard[x - 1][y - 1] = 0;
			return 1;
		}
		else {
			printf("Spot isn't valid , chance lost");
			return 0;
		}
	}
	if (player == 2) {
		if (GameBoard[x - 1][y - 1] == 1) {
			GameBoard[x - 1][y - 1] = 0;
			return 1;
		}
		else {
			printf("Spot isn't valid , chance lost");
			return 0;
		}
	}
	return 0;
}