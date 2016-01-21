/*
Nicolas Kheirallah
Headers for helper.c , contains several functions
*/
int switch_turn(int *t);
int is_enemy(int jag);
int pause();
void write_turn(int *turn);
int check_checker(int GameBoard[9][8],int turn, int y, int x);
int check_steps(int x_pos, int y_pos, int next_x ,int next_y);
int Check_ValidMove(char move_control[9][8], int next_x ,int next_y);
int check_collision(int GameBoard[9][8], int next_x ,int next_y,int turn);
int controll_checkerDirection(int turn, int y_pos, int next_y);
int check_movement(char move_control[9][8],int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y, int turn);
void update_position(int turn, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y);
int takeOver(int turn, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y);
void checker_takeover(int turn, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y,int direction);
int check_sides(int x_pos, int next_x);