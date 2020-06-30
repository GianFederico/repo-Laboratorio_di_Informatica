//inserire qui solo i prototipi delle funzioni che vengono definite in funzioniutili.c

#ifndef FUNZIONIUTILI_H_
#define FUNZIONIUTILI_H_


#include <stdio.h>
#include <stdlib.h>

struct dati_giocatori {     //definizione della struttura
	char cognome[20];
	char nome[20];
	char genere[20];
	char email[50];
	char telefono[16];
	char ruolo[20];
};
typedef struct dati_giocatori GIOCATORE;


#endif /* FUNZIONIUTILI_H_ */
