#include <stdio.h>
#include <stdlib.h>

#define DIM 10
#define DIMM 20
typedef int vettore[DIM];
typedef int vettoreu[DIMM];

void acquisisci_vettore1(vettore vettore1);
void acquisisci_vettore2(vettore vettore1);
void vettore_somma(vettore vettoresomma, vettore vettore1, vettore vettore2);
void stampa_vettore(vettore vettoresomma);
void vettore_unito(vettoreu vettoreunito, vettore vettore1, vettore vettore2);
void stampa_vettoreu(vettore vettoreu);



int main (){
vettore vettore1;
vettore vettore2;
vettore vettoresomma;
vettoreu vettoreunito;

    printf("PRIMO VETTORE:\n");
	acquisisci_vettore1(vettore1);
	printf("_______________________________________\n");
	printf("SECONDO VETTORE:\n");
	acquisisci_vettore2(vettore2);
	printf("_______________________________________\n");
	vettore_somma(vettoresomma,vettore1,vettore2);
	stampa_vettore(vettoresomma);
    vettore_unito(vettoreunito,vettore1,vettore2);
    stampa_vettoreu(vettoreunito);

	system ("pause");
	return 0;
}

//=====================================================================

void acquisisci_vettore1(vettore vettore1){
	int i=0;
	while(i<DIM){
		printf("inserisci il valore %d del vettore: ", i+1);
		scanf("%d",&vettore1[i]);
		i++;
	}
}

//=====================================================================

void acquisisci_vettore2(vettore vettore1){
	int i=0;
	while(i<DIM){
		printf("inserisci il valore %d del vettore: ", i+1);
		scanf("%d",&vettore1[i]);
		i++;
	}
}

//=====================================================================

void vettore_somma(vettore vettoresomma, vettore vettore1, vettore vettore2){
	int i=0;
	while(i<DIM){
		vettoresomma[i]= vettore1[i]+vettore2[i];
		i++;
	}
}

//=====================================================================

void stampa_vettore(vettore vettoresomma){
	int i=0;
	printf("Il vettore somma risulta essere:");
	while(i<DIM){
		printf(" %d ", vettoresomma[i]);
		i++;
	}
	printf("\n");
}

//=====================================================================

void vettore_unito(vettoreu vettoreunito, vettore vettore1, vettore vettore2){
	int i=0;
	while (i<DIMM){
		if(i>9){
			vettoreunito[i]=vettore2[i-DIM];
		}
		else{
		vettoreunito[i]=vettore1[i];
		}
		i++;
	}
}

//=====================================================================

void stampa_vettoreu(vettore vettoreu){
	int i=0;
	printf("Il vettore unito risulta essere:");
	while(i<DIMM){
		printf(" %d ", vettoreu[i]);
		i++;
	}
	printf("\n");
}
