#include "gioco.h"

char griglia[LARGHEZZA_GRIGLIA][ALTEZZA_GRIGLIA];

const char VUOTO = ' ';
const char GIOCATORE = 'P';
const char OSTACOLO = 'O';

// Inizializza la griglia del gioco, posiziona il giocatore e alcuni ostacoli iniziali.
void inizializzaGriglia() {
    for (int i = 0; i < ALTEZZA_GRIGLIA; i++) {
        for (int j = 0; j < LARGHEZZA_GRIGLIA; j++) {
            griglia[i][j] = VUOTO;
        }
    }

    griglia[ALTEZZA_GRIGLIA - 1][LARGHEZZA_GRIGLIA / 2] = GIOCATORE;

    int colonnaOstacolo1 = LARGHEZZA_GRIGLIA / 2 - 2;
    int colonnaOstacolo2 = LARGHEZZA_GRIGLIA / 2 + 2;

    if (colonnaOstacolo1 >= 0 && colonnaOstacolo1 < LARGHEZZA_GRIGLIA)
        griglia[0][colonnaOstacolo1] = OSTACOLO;

    if (colonnaOstacolo2 >= 0 && colonnaOstacolo2 < LARGHEZZA_GRIGLIA)
        griglia[0][colonnaOstacolo2] = OSTACOLO;
}


// Genera casualmente un ostacolo nella parte superiore della griglia.
void generaOstacolo() {
    int colonnaOstacolo = rand() % LARGHEZZA_GRIGLIA;

    if (colonnaOstacolo >= 0 && colonnaOstacolo < LARGHEZZA_GRIGLIA)
        griglia[0][colonnaOstacolo] = OSTACOLO;
}


// Muove il giocatore a sinistra o a destra in modo casuale.
void muoviGiocatore() {
    int rigaGiocatore, colonnaGiocatore;

    for (int i = 0; i < ALTEZZA_GRIGLIA; i++) {
        for (int j = 0; j < LARGHEZZA_GRIGLIA; j++) {
            if (griglia[i][j] == GIOCATORE) {
                rigaGiocatore = i;
                colonnaGiocatore = j;
                griglia[i][j] = VUOTO;
            }
        }
    }

    int direzione = rand() % 2;
    if (direzione == 0 && colonnaGiocatore > 0) {
        colonnaGiocatore--;
    } else if (direzione == 1 && colonnaGiocatore < LARGHEZZA_GRIGLIA - 1) {
        colonnaGiocatore++;
    }

    if (rigaGiocatore < ALTEZZA_GRIGLIA && colonnaGiocatore < LARGHEZZA_GRIGLIA)
        griglia[ALTEZZA_GRIGLIA - 1][colonnaGiocatore] = GIOCATORE;
}


// Muove gli ostacoli verso il basso nella griglia.
void muoviOstacolo() {
    for (int i = ALTEZZA_GRIGLIA - 1; i >= 0; i--) {
        for (int j = 0; j < LARGHEZZA_GRIGLIA; j++) {
            if (griglia[i][j] == OSTACOLO) {
                griglia[i][j] = VUOTO;

                if (i < ALTEZZA_GRIGLIA - 1) {
                    if (j >= 0 && j < LARGHEZZA_GRIGLIA)
                        griglia[i + 1][j] = OSTACOLO;
                } else {
                    generaOstacolo();
                }
            }
        }
    }
}


// Controlla se c'è una collisione tra il giocatore e un ostacolo nella posizione corrente.
int controllaCollisione() {
    if (ALTEZZA_GRIGLIA > 0 && LARGHEZZA_GRIGLIA / 2 >= 0 && LARGHEZZA_GRIGLIA / 2 < LARGHEZZA_GRIGLIA)
        return (griglia[ALTEZZA_GRIGLIA - 1][LARGHEZZA_GRIGLIA / 2] == OSTACOLO);
    return 0;
}


// Stampa la griglia del gioco a schermo, inclusi il giocatore e gli ostacoli.
void stampaGriglia() {
    system(CLEAR_SCREEN);

    printf("%s-", COLORE_BLU);

    for (int i = 0; i < LARGHEZZA_GRIGLIA * 6 - 1; i++) {
        printf("-");
    }

    printf("-%s\n", COLORE_RESET);

    for (int i = 0; i < ALTEZZA_GRIGLIA; i++) {
        printf("%s|", COLORE_BLU);

        for (int j = 0; j < LARGHEZZA_GRIGLIA; j++) {
            if (i < ALTEZZA_GRIGLIA && j < LARGHEZZA_GRIGLIA)
                printf("%s  %c  %s|", COLORE_GIALLO, griglia[i][j], COLORE_BLU);
        }

        printf("\n");

        if (i < ALTEZZA_GRIGLIA - 1) {
            printf("%s|", COLORE_BLU);

            for (int j = 0; j < LARGHEZZA_GRIGLIA; j++) {
                printf("%s|", LINEA_ORIZZONTALE);
            }

            printf("\n");
        }
    }

    printf("%s-", COLORE_BLU);

    for (int i = 0; i < LARGHEZZA_GRIGLIA * 6 - 1; i++) {
        printf("-");
    }

    printf("-%s\n", COLORE_RESET);
}


// Esegue una partita del gioco, gestendo i movimenti del giocatore e degli ostacoli.
void eseguiPartita() {
    int passi = 0;

    while (passi < MASSIMI_PASSI) {
        stampaGriglia();
        printf("Passo %d - Premi Invio per continuare al prossimo passo...", passi + 1);
        getchar(); // Aspetta l'input dell'utente per continuare

        muoviGiocatore();
        muoviOstacolo();

        if (controllaCollisione()) {
            printf("\nGame Over! Il giocatore ha colliso con un ostacolo.\n");
            break;
        }

        passi++;
    }

    printf("\nGame Over! Massimi passi raggiunti.\n");
}