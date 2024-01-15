#include "gioco.h"


// Funzione principale del programma.
int main() {

    // Inizializza il generatore di numeri casuali con il tempo corrente.
    srand((unsigned int)time(NULL));


    // Inizializza la griglia di gioco e posiziona il giocatore e gli ostacoli iniziali.
    inizializzaGriglia();

    // Esegue una partita del gioco, gestendo i movimenti del giocatore e degli ostacoli.
    eseguiPartita();


    // Termina il programma senza errori.
    return 0;
}