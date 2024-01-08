// Inizializzazione e definizione di una variabile UNIVERSALE di parametri
#define MESI 12
#define GIORNI 30
#define ORE 24
#define CATEGORIE 3

// Inizializzazione e Definizione dell'ANSI ESCAPE CODE per lavorare in una GRID TABLE colorata
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RESET "\033[0m"

// Inizializzazione della STRUCT
struct Appuntamento {
    int categoria;
};

// Inizializzazione di una VARIABILE UNIVERSALE
extern const char *nomiCategorie[CATEGORIE];

// Inizializzazione dei prototipi delle funzioni
void aggiungiAppuntamento(struct Appuntamento agenda[MESI][GIORNI][ORE]);
void calcolaOreCategoria(struct Appuntamento agenda[MESI][GIORNI][ORE]);
void descriviStatistiche(struct Appuntamento agenda[MESI][GIORNI][ORE]);
void eseguiOperazioniAgenda(struct Appuntamento agenda[MESI][GIORNI][ORE]);