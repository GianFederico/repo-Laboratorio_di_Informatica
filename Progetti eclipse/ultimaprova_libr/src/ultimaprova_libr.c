#include<stdio.h>
#include <stdlib.h>


void ordina_vett(int vett[],int DIM){
int i=0;
int pass=1;
int temp;

while(pass<DIM){
	i=0;
	while(i<DIM){
		if(vett[i]>vett[i+1]){
			temp=vett[i];
			vett[i]=vett[i+1];
			vett[i+1]=temp;
		}
		i++;
	}
	pass++;
}

}

void stampa_vett(int vett[], int DIM){
	int i=0;
	printf("il vettore ordinato e': ");

	while(i<DIM){
		printf("%d ",vett[i]);
		i++;
	}
}
