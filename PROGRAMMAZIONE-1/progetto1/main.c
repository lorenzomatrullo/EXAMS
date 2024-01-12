#include "gioco.h"

int main() {
    srand((unsigned int)time(NULL));

    inizializzaGriglia();
    eseguiPartita();

    return 0;
}