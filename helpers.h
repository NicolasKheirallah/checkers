/*
Nicolas Kheirallah
Headers for helper.c , contains several functions
*/
int switch_player(int *player);
int is_enemy(int checker);
int pause();
void write_turn(int *player);
int check_checker(int GameBoard[9][8],int player, int x, int y);
int check_steps(int x_pos, int y_pos, int next_x ,int next_y);
int Check_ValidMove(char move_control[9][8], int next_x ,int next_y);
int check_collision(int GameBoard[9][8], int next_x ,int next_y,int player);
int controll_checkerDirection(int player, int y_pos, int next_y);
int check_movement(char move_control[9][8],int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y, int player);
void update_position(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y);
int takeOver(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y);
void checker_takeover(int player, int GameBoard[9][8], int x_pos, int y_pos, int next_x ,int next_y,int direction);
int check_sides(int x_pos, int next_x);