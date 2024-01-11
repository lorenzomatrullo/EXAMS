#include "game.h"
#include <stdio.h>

int main() {
    initializeBoard();
    
    int steps = 0;
    
    while (steps < 100) {
        printBoard();
        printf("Step %d - Press Enter to continue to the next step...", steps + 1);
        getchar(); // Wait for user input to continue

        movePlayer();
        moveObstacle();

        if (checkCollision()) {
            printf("\nGame Over! The player collided with an obstacle.\n");
            break;
        }

        steps++;
    }

    printf("\nGame Over! Maximum steps reached.\n");

    return 0;
}