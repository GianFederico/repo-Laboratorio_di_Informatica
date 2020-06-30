#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dati_brani {
	char artista[30];
	char titolo[30];
	char genere[30];
	int  stelle;
};
typedef struct dati_brani BRANO;


struct canzoni {
		BRANO iperstruct;
	};
typedef struct canzoni PLAYLIST;


#ifndef HEADER_PER_CUNIT_H_
#define HEADER_PER_CUNIT_H_


void menu ();
int  conta_playlist (FILE *pfile, int cont_pl);
int  conta_righe(FILE *pfile, int cont_tracce);
void visualizza_brani (FILE *pfile, BRANO *struttura, int cont_tracce);
void ricerca_brano (FILE *pfile, BRANO *struttura, int cont_tracce);
int aggiungi_brano (FILE *pfile, BRANO *struttura);
int visualizza_playlist (FILE *pfile);
void componi_playlist (FILE *pfile, BRANO *struttura, PLAYLIST *megastruct, int cont_tracce);
int ordina_brani (FILE *pfile, BRANO *struttura, int cont_tracce);

#endif /* FUNZIONI_UTILIZZATE_H_ */
