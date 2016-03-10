/*
	Nicolas Kheirallah
Creates the GameBoard and the main rules of the game
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "player.h"

void update_checker(int player);
void use_bonus(int c, int player, int GameBoard[9][8], char move_control[9][8]);

int playerTurn = 1;//what turn it is
int rounds = 20;
// Numbers of moves players start with
int player1 = 12;
int player2 = 12;



//Movement the pieces can walk , X = B and O =W  , Must be improved with a cleaner verison
char move_control[9][8] = {'B','W','B','W','B','W','B','W',
						   'W','B','W','B','W','B','W','B',
                           'B','W','B','W','B','W','B','W',
                           'W','B','W','B','W','B','W','B',
                           'B','W','B','W','B','W','B','W',
                           'W','B','W','B','W','B','W','B',
                           'B','W','B','W','B','W','B','W',
                           'W','B','W','B','W','B','W','B'};

int GameBoard[9][8] =
{ 1,0,1,0,1,0,1,0, 
 0,1,0,1,0,1,0,1,
 1,0,1,0,1,0,1,0,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 0,2,0,2,0,2,0,2,
 2,0,2,0,2,0,2,0,
 0,2,0,2,0,2,0,2
};


void draw_GameBoard(int GameBoard[9][8])
{
	//coordinater
	int x, y;//Wide and Hight
	int z = 1;
	system("cls");
	for (y = 0; y < 8; y++) {
		printf("%d", z); // numbers on the side
		z++;
		for (x = 0; x < 8; x++) {
			printf("|");//creates the wall
			switch (GameBoard[x][y]) { // when they reach the end they become caps
			case 0:
				printf(" ");
				break;
			case 1:
				printf("x");
				break;
			case 2:
				printf("o");
				break;
			case 3:
				printf("X");
				break;
			case 4:
				printf("O");
				break;
			}
		}
		printf("|\n");
	}
	printf("  1 2 3 4 5 6 7 8\n");
}





//The logic for moving the checkers
void move_phase()
{

	int control = 0;
	int x, y;//x postions and Y position
	int  next_x,next_y=0;//next position of the checker
	printf("turns left: %d \n", rounds);
	printf("Life left for Player1 :%d ", player1);
	printf("and Player2: %d \n",player2);
	
	while(control == 0)
	{
		x = 0, y = 0;
		printf("\n Input first X and then Y value for the piece you want to move , if you can't move type 0 and then 0 \n");
		scanf_s("\n %d %d",&x,&y);

		if(check_checker(GameBoard, playerTurn,x,y) == 1 ){

			while(1){
				
				next_x = 0, next_y = 0;
				printf(" Input first X and then Y value for the piece you want to move .\n OR type: '-1' and '-1' for going back one step\n");
				scanf_s("%d %d",&next_x,&next_y);
				if(next_x == -1 && next_y == -1){
					//next turn
					break;
				}
				if(check_movement(move_control,GameBoard,x,y,next_x,next_y, playerTurn) == 1){ // Enemy
					if(takeOver(playerTurn,GameBoard, x, y, next_x, next_y) == 1){
						update_checker(playerTurn);
						control = 1;
						break;
					}
					else if(takeOver(playerTurn,GameBoard, x, y, next_x, next_y) == 0){ // your own piece is behind you
						printf("Invalid move!\n");
						break;
					}
					else if(takeOver(playerTurn,GameBoard, x, y, next_x, next_y) == 2){ //no Enemy
						update_position(playerTurn,GameBoard, x, y, next_x, next_y);
						control = 1;
						break;
					}
				}
			}
		}
		else if (x == 0 && y == 0) {// if you cant move input this
			control = 1;
			break;
		}
		else{
			printf("\n No magic here");
		}

	}//end control while
	if(check_GameBoard_end(playerTurn,next_y)){
		int c;
		printf("Choose checker to delete ! :");
		c = bonus();
		use_bonus(c, playerTurn,GameBoard, move_control);
		pause();
	}
	rounds = rounds -1;
}

//Checks amount of checkers and the one with the most wins
void winner(){
	if(player2 < player1){
		printf("Player 1 has won this round! ");
	}
	if(player1 < player2){
		printf("Player 2 has won this round ");
	}
	if(player1 == player2){
		printf("No one wins!");
	}
}




// runs the game
void run()
{	
	while(rounds!=0){
		draw_GameBoard(GameBoard);//creates the GameBoard
		write_turn(&playerTurn);
		move_phase();
		playerTurn = changeTurn(&playerTurn); //next turn
	}
	winner();
	pause();
}




// Remove checkers
void update_checker(int player)
{
	if(player == 1){
		player2 = player2-1;
	}
	if(player == 2){
		player1 = player1-1;
	}
}

// remove checker when reaching the end
void use_bonus(int c, int player, int GameBoard[9][8], char move_control[9][8])
{
	if(c == 1){
		int del;
		del = delete_enemy(player, GameBoard);
		if(del == 1){
			if(player == 1){
				player2 = player2 - 1;
			}
			if(player == 2){
				player1 = player1 - 1;
			}
		}
	}
}