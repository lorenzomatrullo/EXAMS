#ifndef GAME_H
#define GAME_H

#define GRID_WIDTH 7
#define GRID_HEIGHT 6

#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_RESET "\033[0m"
#define LINE_HORIZONTAL "-----"
#define LINE_VERTICAL "|"

extern const char EMPTY;
extern const char PLAYER;
extern const char OBSTACLE;

extern char board[GRID_WIDTH][GRID_HEIGHT];

void initializeBoard();
void printBoard();
void spawnObstacle();
void movePlayer();
void moveObstacle();
int checkCollision();

#endif