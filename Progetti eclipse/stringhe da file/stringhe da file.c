#include <stdio.h>
#include <stdlib.h>
struct dati_giocatori {
	char cognome[20];
	char nome[20];
	char genere[20];
	char email[50];
	char telefono[16];
	char ruolo[20];
};

typedef struct dati_giocatori GIOCATORE;

void lettura(FILE *file, GIOCATORE *vettore, int dim);
void stampa(GIOCATORE *vettore, int dim);

int main (){
	FILE *file;
	GIOCATORE *vettore;
	int dim=0;

	vettore=(GIOCATORE*)malloc(dim*sizeof(GIOCATORE));
		printf("Quanti giocatori vuoi visualizzare?");
		scanf("%d",&dim);


	file=fopen("Giocatoriprova.txt","r");

	lettura(file,vettore,dim);
	system("pause");
	stampa(vettore,dim);

	system("pause");
	return 0;

}

void lettura(FILE *file, GIOCATORE *vettore, int dim){
	int i=0;
		if((file=fopen("Giocatoriprova.txt","r"))!=NULL){
			while(i<dim){
				 fscanf(file,"%s %s %s %s %s %s",vettore[i].cognome,vettore[i].nome,vettore[i].genere,
						 vettore[i].email,vettore[i].telefono,vettore[i].ruolo);
				   i++;
			}
		}
            else{
                printf("Error.");
            }
}


void stampa(GIOCATORE *vettore, int dim){
	int i=0;
	while(i<dim){
		printf("%s, %s, %s, %s, %s, %s.\n", vettore[i].cognome,vettore[i].nome,vettore[i].genere,
				vettore[i].email,vettore[i].telefono,vettore[i].ruolo);
	i++;
	}
}






