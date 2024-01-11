#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char EMPTY = ' ';
const char PLAYER = 'P';
const char OBSTACLE = 'O';

char board[GRID_WIDTH][GRID_HEIGHT];

void initializeBoard() {
    for (int i = 0; i < GRID_HEIGHT; i++)
        for (int j = 0; j < GRID_WIDTH; j++)
            board[i][j] = EMPTY;

    // Set the player at the last row and center
    board[GRID_HEIGHT - 1][GRID_WIDTH / 2] = PLAYER;

    // Set two obstacles symmetrically in the first row
    int obstacleColumn1 = GRID_WIDTH / 2 - 2;
    int obstacleColumn2 = GRID_WIDTH / 2 + 2;
    board[0][obstacleColumn1] = OBSTACLE;
    board[0][obstacleColumn2] = OBSTACLE;
}

void spawnObstacle() {
    int obstacleColumn = rand() % GRID_WIDTH;
    board[0][obstacleColumn] = OBSTACLE;
}

void movePlayer() {
    // Trova la posizione attuale del player
    int playerRow, playerColumn;
    
    for (int i = 0; i < GRID_HEIGHT; i++){
        for (int j = 0; j < GRID_WIDTH; j++){
            if (board[i][j] == PLAYER) {
                playerRow = i;
                playerColumn = j;
                board[i][j] = EMPTY;
            }
        }
    }

    // Sposta il player a destra o sinistra in modo casuale
    int direction = rand() % 2; // 0 per sinistra, 1 per destra
    playerColumn += (direction == 0 && playerColumn > 0) ? -1 : (direction == 1 && playerColumn < GRID_WIDTH - 1) ? 1 : 0;

    // Sposta il player nella nuova posizione
    board[GRID_HEIGHT - 1][playerColumn] = PLAYER;
}

void moveObstacle() {

    // Move obstacles downward
    for (int i = GRID_HEIGHT - 1; i >= 0; i--){
        for (int j = 0; j < GRID_WIDTH; j++){
            if (board[i][j] == OBSTACLE) {
                board[i][j] = EMPTY;
                if (i < GRID_HEIGHT - 1){
                    board[i + 1][j] = OBSTACLE;
                } else {
                    spawnObstacle();
                }
            }
        }
    }
}

int checkCollision() {
    // Check if the player collided with an obstacle
    return (board[GRID_HEIGHT - 1][GRID_WIDTH / 2] == OBSTACLE);
}

void printBoard() {
    system("cls"); // Clear the console (for UNIX-like systems, change if needed)

    printf("%s-", COLOR_BLUE);

    for (int i = 0; i < GRID_WIDTH * 6 - 1; i++){
        printf("-");
    }

    printf("-%s\n", COLOR_RESET);

    for (int i = 0; i < GRID_HEIGHT; i++) {

        printf("%s|", COLOR_BLUE);

        for (int j = 0; j < GRID_WIDTH; j++){
            printf("%s  %c  %s|", COLOR_YELLOW, board[i][j], COLOR_BLUE);
        }

        printf("\n");

        if (i < GRID_HEIGHT - 1) {
            printf("%s|", COLOR_BLUE);

            for (int j = 0; j < GRID_WIDTH; j++){
                printf("%s|", LINE_HORIZONTAL);
            }

            printf("\n");
        }
    }

    printf("%s-", COLOR_BLUE);

    for (int i = 0; i < GRID_WIDTH * 6 - 1; i++){
        printf("-");
    }

    printf("-%s\n", COLOR_RESET);
}