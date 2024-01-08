#include <stdio.h>
#include "agenda.h" // includo l'header "agenda.h" 

int main() {

    // Inizializzazione dell'agenda a zero
    struct Appuntamento agenda[MESI][GIORNI][ORE] = {{{0}}};

    // Esegue le operazioni dell'agenda
    eseguiOperazioniAgenda(agenda);
    
    return 0;
}