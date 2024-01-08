#include <stdio.h>
#include "agenda.h"

// Costante fissa per le categorie dell'agenda
const char *nomiCategorie[CATEGORIE] = {"Lavoro", "Casa", "Sport"};


// Aggiunge un appuntamento nell'agenda per una specifica data e ora 
void aggiungiAppuntamento(struct Appuntamento agenda[MESI][GIORNI][ORE]) {
    int mese, giorno, ora, categoria;

    // Chiede all'utente di inserire i dettagli dell'appuntamento
    printf("\nInserisci il mese (1-12): ");
    scanf("%d", &mese);

    printf("Inserisci il giorno (1-30): ");
    scanf("%d", &giorno);

    printf("Inserisci l'ora (0-23): ");
    scanf("%d", &ora);

    printf("Seleziona la categoria (1 = lavoro, 2 = casa, 3 = sport): ");
    scanf("%d", &categoria);

    // Assegna l'appuntamento nell'agenda nella posizione specificata
    // uso [mese - 1] e [giorno - 1] per poter lavorare in un range che parte da 1 invece di 0
    agenda[mese - 1][giorno - 1][ora].categoria = categoria;

    // Stampa che la registrazione è andata a buon fine
    printf("\n%sAppuntamento aggiunto!%s\n", COLOR_GREEN, COLOR_RESET);
}



// Calcola le ore dedicate a una categoria in un intervallo di date
void calcolaOreCategoria(struct Appuntamento agenda[MESI][GIORNI][ORE]) {

    // dichiarazione delle variabili
    int categoria, mese1, giorno1, mese2, giorno2;
    
    // Chiede all'utente la categoria e l'intervallo di date
    printf("Seleziona la categoria (1 = lavoro, 2 = casa, 3 = sport): ");
    scanf("%d", &categoria);

    printf("Inserisci la data di inizio (mese giorno): ");
    scanf("%d %d", &mese1, &giorno1);

    printf("Inserisci la data di fine (mese giorno): ");
    scanf("%d %d", &mese2, &giorno2);

    // variabile che semplifica la lettura
    int oreDedicate = 0;
    int meseInizio = mese1 - 1;
    int giornoInizio = giorno1 - 1;
    int meseFine = mese2 - 1;

    // For loop che calcola le ore totali dedicate alla categoria nell'intervallo specificato
    for (int mese = meseInizio; mese < meseFine; mese++) {
        int giornoDiInizio = giornoInizio;
        if (mese != meseInizio) {
            giornoDiInizio = 0;
        }

        int giornoFine = GIORNI;
        if (mese == meseFine) {
            giornoFine = giorno2;
        }

        // for loop che filtra dall'inizio alla fine dei giorni scelti
        for (int giorno = giornoDiInizio; giorno < giornoFine; giorno++) {
            for (int ora = 0; ora < ORE; ora++) {
                int categoriaCorrente = agenda[mese][giorno][ora].categoria;
                if (categoriaCorrente == categoria) {
                    // aumento del counter delle ore dedicate alla categoria
                    oreDedicate++;
                }
            }
        }
    }

    // Stampa che le ore sono state aggiunte
    printf("\n%sOre totali dedicate a %s: %d%s\n", COLOR_GREEN, nomiCategorie[categoria - 1], oreDedicate, COLOR_RESET);
}




// Descrive le statistiche delle ore dedicate a ogni categoria
void descriviStatistiche(struct Appuntamento agenda[MESI][GIORNI][ORE]) {

    // Counter delle ore che parte da 0
    int orePerCategoria[CATEGORIE] = {0};

    // Calcola il numero di ore per ogni categoria nell'intera agenda
    // Triplo nested for loop che passa per tutti i parametri che abbiamo registrato in precedenza
    for (int mese = 0; mese < MESI; mese++) {
        for (int giorno = 0; giorno < GIORNI; giorno++) {
            for (int ora = 0; ora < ORE; ora++) {
                // variabile che semplifica la lettura
                int categoriaCorrente = agenda[mese][giorno][ora].categoria;
                // aumenta il counter delle ore
                orePerCategoria[categoriaCorrente - 1]++;
            }
        }
    }

    // Stampa le statistiche delle ore per ogni categoria
    printf("\n%sStatistiche delle ore dedicate a ogni categoria:\n", COLOR_GREEN);
    printf("%s: %d ore\n", nomiCategorie[0], orePerCategoria[0]);
    printf("%s: %d ore\n", nomiCategorie[1], orePerCategoria[1]);
    printf("%s: %d ore%s\n", nomiCategorie[2], orePerCategoria[2], COLOR_RESET);
}




// Esegue le operazioni dell'agenda attraverso un menu interattivo
void eseguiOperazioniAgenda(struct Appuntamento agenda[MESI][GIORNI][ORE]) {
    int scelta;

    // uso del do while loop per riproporre il codice fin quando non si ha in output l'uscita dettata dall'interno (4)
    do {
        // Mostra il menu delle operazioni
        printf("\nMenu:\n");
        printf("1. Aggiungi un appuntamento\n");
        printf("2. Mostra le ore dedicate a una categoria in un intervallo di date\n");
        printf("3. Descrivi le statistiche delle ore dedicate a ogni categoria\n");
        printf("4. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        // Esegue l'operazione scelta dall'utente
        switch (scelta) {
            case 1:
                // avviamento della funzione
                aggiungiAppuntamento(agenda);
                break;
            case 2:
                // avviamento della funzione
                calcolaOreCategoria(agenda);
                break;
            case 3:
                // avviamento della funzione
                descriviStatistiche(agenda);
                break;
            case 4:
                printf("Uscita...\n");
                break;
            default:
                // se viene scelta qualsiasi altro caso non compreso tra 1 e 4, il blocco di istruzione riparte
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 4);
}