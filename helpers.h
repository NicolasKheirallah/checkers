/*
Nicolas Kheirallah
Headers for helper.c , contains several functions
*/
void write_turn(int *player);
void checker_takeover(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y, int direction);
void update_position(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x, int next_y);

int changeTurn(int *p);
int is_enemy(int checker);
int pause();
int check_checker(int GameBoard[9][8],int player, int x, int y);
int check_steps(int x_pos, int y_pos, int next_x ,int next_y);
int Check_ValidMove(char move_control[9][8], int next_x ,int next_y);
int check_collision(int GameBoard[9][8], int next_x ,int next_y,int player);
int controll_checkerDirection(int player, int y_pos, int next_y);
int check_movement(char move_control[9][8],int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y, int player);
int takeOver(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y);
int check_sides(int x_pos, int next_x);