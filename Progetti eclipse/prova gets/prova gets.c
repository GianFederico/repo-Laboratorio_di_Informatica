#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dati_giocatori {
	char cognome[20];
	char nome[20];
	char genere[20];
	char email[50];
	char telefono[16];
	char ruolo[20];
};

typedef struct dati_giocatori GIOCATORE;

void assegnastampa(FILE *pfile, GIOCATORE *vettore, int dim);


int main(){
	FILE *pfile;
	GIOCATORE *vettore;
	int dim=0;



	int i=0;
		char nome[20];
		char cognome[20];
		printf("Inserisci il nome della persona da ricercare: ");
		gets(nome);
		printf("Inserisci il cognome della persona da ricercare: ");
		gets(cognome);

		printf("%s,%s",nome,cognome);
		system("pause");
}








