#ifndef GIOCO_H
#define GIOCO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define LARGHEZZA_GRIGLIA 7
#define ALTEZZA_GRIGLIA 6
#define MASSIMI_PASSI 100

#define COLORE_GIALLO "\033[1;33m"
#define COLORE_BLU "\033[0;34m"
#define COLORE_RESET "\033[0m"
#define LINEA_ORIZZONTALE "-----"
#define LINEA_VERTICALE "|"


// Simboli per rappresentare i tipi di cella nella griglia del gioco.
extern const char VUOTO;
extern const char GIOCATORE;
extern const char OSTACOLO;


// Funzioni definite nel file gioco.c
void inizializzaGriglia();
void generaOstacolo();
void muoviGiocatore();
void muoviOstacolo();
int controllaCollisione();
void stampaGriglia();
void eseguiPartita();

#endif