/*
Nicolas Kheirallah
In this part we have the rules for movement
*/

#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

int edge[9][8] =	 { 1,1,1,1,1,1,1,1, // 1 = the edge of the board
					   1,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,1,
					   1,1,1,1,1,1,1,1
};


int switch_player(int *player)
{
	if (*player == 1) {
		return 2;//change turns
	}
	if (*player == 2) {
		return 1;
	}
	return 0;
}




int is_enemy(int checker) //checks if it's an enemy you move to
{
	if (checker == 1 || checker == 3) {
		return 2;
	}
	if (checker == 2 || checker == 4) {
		return 1;
	}
	return 0;
}




int pause() //selfexplaining
{
	int c;
	printf("\n PRESS ENTER to CONTINUE");
	while ((c = getchar()) != '\n' && c != EOF); //EOF =End of File
	return 0;
}


void write_turn(int *player)//Writes who's turn
{
	if (*player == 1) {
		printf("X turn\n");
	}
	if (*player == 2) {
		printf("O turn\n");
	}
}


int check_checker(int GameBoard[9][8], int player, int x, int y)//check checker coordinates
{
	if (player == 1) {
		if (GameBoard[x - 1][y - 1] == 1) {
			return 1;
		}
	}
	if (player == 2) {
		if (GameBoard[x - 1][y - 1] == 2) {
			return 1;
		}
	}
	return 0;
}





int check_steps(int x_pos, int y_pos, int next_x, int next_y) //player can only move one step
{
	if ((next_y > y_pos + 1 || next_x > x_pos + 1) ||
		(next_y < y_pos - 1 || next_x < x_pos - 1)) {
		return 0;
	}
	else {
		return 1;
	}
}


int Check_ValidMove(char move_control[9][8], int next_x, int next_y)
{
	if (move_control[next_y - 1][next_x - 1] == 'B') {
		return 1;
	}
	else {
		return 0;
	}
}






int check_collision(int GameBoard[9][8], int next_x, int next_y, int player) // checks so the checkers doesn't collide
{
	if (player == 1) {
		if (GameBoard[next_x - 1][next_y - 1] == 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (player == 2) {
		if (GameBoard[next_x - 1][next_y - 1] == 2) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return 0;
}


int controll_checkerDirection(int player, int y_pos, int next_y)
{
	if (player == 1) {
		if (y_pos - 1 > next_y - 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (player == 2) {
		if (y_pos - 1 < next_y - 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return 0;
}


int check_movement(char move_control[9][8], int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y, int player)
{
	if (check_steps(x_pos, y_pos, next_x, next_y) != 1) {
		printf("Only one step is allowed !\n");
		return 0;
	}
	else if (Check_ValidMove(move_control, next_x, next_y) != 1) {
		printf("\n  Only Sideways is alowed!\n");
		return 0;
	}
	else if (check_collision(GameBoard, next_x, next_y, player) != 1) {
		printf("\n Invalid move!\n");
		return 0;
	}
	else if (controll_checkerDirection(player, y_pos, next_y) != 1) {
		printf("\n Wrong way!\n");
		return 0;
	}
	else {
		return 1;
	}
}



void update_position(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y)
{
	if (player == 1) {
		GameBoard[x_pos - 1][y_pos - 1] = 0;//removes old position
		GameBoard[next_y - 1][next_x - 1] = 1;
	}
	if (player == 2) {
		GameBoard[x_pos - 1][y_pos - 1] = 0;
		GameBoard[next_y - 1][next_x - 1] = 2;
	}
}




int check_sides(int x_pos, int next_x)
{
	if (x_pos < next_x) {//checks right
		return 1;
	}
	if (x_pos > next_x) {//checks left
		return 2;
	}
	return 0;
}




int at_edge(int next_x, int next_y)//checks if we are at the edge
{
	if (edge[next_x - 1][next_y - 1] == 1) {
		return 0;
	}
	else {
		return 1;
	}
}






int takeOver(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y)
{
	int direction = check_sides(x_pos, next_x);
	if (player == 1) {// right
		if (GameBoard[next_x - 1][next_y - 1] == 2) {//Enemy detected
			if (direction == 1) {
				if (GameBoard[(next_x - 1) + 1][(next_y - 1) + 1] == 2) {
					return 0;
				}
				else if (GameBoard[(next_x - 1) + 1][(next_y - 1) + 1] == 1) {
					return 0;
				}
				else {//checks if enemy is at the edge
					if (at_edge(next_x, next_y) == 1) {
						checker_takeover(player, GameBoard, x_pos, y_pos, next_x, next_y, direction);
						return 1;
					}
					return 0;
				}
			}
			else if (direction == 2) {//left
				if (GameBoard[(next_x - 1) + 1][(next_y - 1) - 1] == 2) {
					return 0;
				}
				else if (GameBoard[(next_x - 1) + 1][(next_y - 1) - 1] == 1) {
					return 0;
				}
				else {
					if (at_edge(next_x, next_y) == 1) {
						checker_takeover(player, GameBoard, x_pos, y_pos, next_x, next_y, direction);
						return 1;
					}
					return 0;
				}
			}
		}
		else {
			return 2;
		}
	}
	if (player == 2) {
		if (GameBoard[next_x - 1][next_y - 1] == 1) {

			if (direction == 1) {
				if (GameBoard[(next_x - 1) - 1][(next_y - 1) + 1] == 1) {
					return 0;
				}
				else if (GameBoard[(next_x - 1) - 1][(next_y - 1) + 1] == 2) {
					return 0;
				}
				else {
					if (at_edge(next_x, next_y) == 1) {
						checker_takeover(player, GameBoard, x_pos, y_pos, next_y, next_x, direction);
						return 1;
					}
					return 0;
				}
			}
			else if (direction == 2) {
				if (GameBoard[(next_x - 1) - 1][(next_y - 1) - 1] == 1) {
					return 0;
				}
				else if (GameBoard[(next_x - 1) - 1][(next_y - 1) - 1] == 2) {
					return 0;
				}
				else {
					if (at_edge(next_x, next_y) == 1) {
						checker_takeover(player, GameBoard, x_pos, y_pos, next_x, next_y, direction);
						return 1;
					}
					return 0;
				}
			}
		}
		else {
			return 2;
		}
	}
	return 0;
}

void checker_takeover(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y, int direction) //updates the position after a takeover
{
	switch (player)
	{
	case 1:
		if (direction == 1) {
			GameBoard[next_x - 1][next_y - 1] = 0;
			update_position(player, GameBoard, x_pos, y_pos, next_x + 1, next_y + 1);
		}
		if (direction == 2) {
			GameBoard[next_x - 1][next_y - 1] = 0;
			update_position(player, GameBoard, x_pos, y_pos, next_x + 1, next_y - 1);
		}
		break;
	case 2:
		if (direction == 1) {
			GameBoard[next_x - 1][next_y - 1] = 0;
			update_position(player, GameBoard, x_pos, y_pos, next_x - 1, next_y + 1);
		}
		if (direction == 2) {
			GameBoard[next_x - 1][next_y - 1] = 0;
			update_position(player, GameBoard, x_pos, y_pos, next_x - 1, next_y - 1);
		}
		break;
	}
}
