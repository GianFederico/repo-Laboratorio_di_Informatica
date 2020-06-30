//RICERCA BINARIA CON VETTORE INSERITO DA TASTIERA DIRETTAMENTE ORDINATO (IMPORTANTE CHE SIA ORDINATO)
#include <stdio.h>
#include <stdlib.h>
#define DIM 10


int ricerca (int *vett, int dim, int valore);

int main(){
	int i=0;
	int vettore[DIM];
	int val;
	int posiz;

	printf("INSERISCI GLI ELEMENTI GIA' ORDINATI\n\a");

	while(i<DIM){
		printf("inserisci l'elemento %d: ",i+1);
		scanf("%d",&vettore[i]);

		i++;
	}

     printf("inserisci l'elemento da ricercare: ");
     scanf("%d",&val);


	ricerca(vettore,DIM, val);
	posiz=ricerca (vettore,DIM,val);
    if (posiz!=-1){
    	printf("elemento trovato in posizione: %d\n", posiz+1);
    }
    else {
    	printf("l'elemento non e' stato trovato.\n");
    }

	system("pause");
	return 0;
}


int ricerca (int *vett,int dim, int valore){
	int primo;
	int ultimo;
	int media;

	primo=0;
	ultimo=dim-1;
	while(primo<=ultimo){
		media=(primo+ultimo)/2;

		if(vett[media]==valore){
			return media;
		}
		else if(vett[media]<valore){
			primo=media+1;
		}
		else if(vett[media]>valore){
			ultimo=media-1;
		}
	}
	return -1;
}










