/*
¨Nicolas Kheirallah
Headers for Player.c and Game.C , contains several functions
*/

int check_GameBoard_end(int turn, int next_y);
int bonus();
void draw_GameBoard(int GameBoard[9][8]);
int delete_enemy(int turn, int GameBoard[9][8]);
void move_phase();
void run();
