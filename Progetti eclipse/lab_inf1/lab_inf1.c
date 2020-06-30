#include <stdlib.h>
#include <stdio.h>

struct studente {
	int matricola;
	char nome[20];
	char cognome[20];
};

typedef struct studente STUDENTE;

//=========================================================================
int main (){
	STUDENTE vettore;

	printf("Inserisci il nome: ");
	scanf("%s",vettore.nome);
	printf("Inserisci il cognome: ");
	scanf("%s",vettore.cognome);
	printf("Inserisci il numero di matricola: ");
	scanf("%d",&vettore.matricola);

	printf("\nNOME:%s\nCOGNOME:%s\nMATRICOLA:%d\n",vettore.nome,vettore.cognome,vettore.matricola);



	system("pause");
	return 0;
}
