#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define GRID_WIDTH 7
#define GRID_HEIGHT 6

#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RESET "\033[0m"
#define COLOR_BLUE "\033[0;34m"
#define LINE_HORIZONTAL "-----"
#define LINE_VERTICAL "|"

char board[GRID_WIDTH][GRID_HEIGHT];
const char PLAYER = 'P';
const char COMPUTER = 'O';

void playerSpawn();
void computerSpawn();
void printBoard();

int main(){

    playerSpawn();
    computerSpawn();
    printBoard();

    return 0;
}

void playerSpawn() {
    int playerX = GRID_WIDTH / 2; // Center column
    int playerY = GRID_HEIGHT - 1; // Bottom row

    // Set the player at the bottom center cell
    board[playerY][playerX] = PLAYER;
}

void computerSpawn() {
    int computerX = GRID_WIDTH / 2; // Center column
    int computerY = 0; // Top row

    // Spawn two additional players symmetrically at the top
    board[computerY][computerX - 2] = COMPUTER;
    board[computerY][computerX + 2] = COMPUTER;
}

void printBoard() {
    // Initialize the board
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Set the players
    playerSpawn();
    computerSpawn();

    // TOP BORDER
    printf("%s-", COLOR_BLUE);
    for (int i = 0; i < (GRID_WIDTH * 6) - 1; i++) {
        printf("-");
    }
    printf("-%s\n", COLOR_RESET);

    // Print the board with colored cells and grid lines
    for (int i = 0; i < GRID_HEIGHT; i++) {

        // LEFT BORDER
        printf("%s|", COLOR_BLUE);

        for (int j = 0; j < GRID_WIDTH; j++) {
            printf("%s  %c  %s", COLOR_YELLOW, board[i][j], COLOR_RESET); // Print cell with yellow color
            printf("%s|", COLOR_BLUE); // Vertical grid line
        }
        printf("\n");

        if (i < GRID_HEIGHT - 1) {

            printf("%s|", COLOR_BLUE); // Left border of the separator row

            for (int j = 0; j < GRID_WIDTH; j++) {
                printf("%s|", LINE_HORIZONTAL, LINE_HORIZONTAL, COLOR_BLUE); // Horizontal grid line for the separator row
            }
            printf("\n");
        }
    }

    // BOTTOM BORDER
    printf("%s-", COLOR_BLUE);

    for (int i = 0; i < GRID_WIDTH * 6 - 1; i++) {
        printf("-");
    }

    printf("-%s\n", COLOR_RESET);
}