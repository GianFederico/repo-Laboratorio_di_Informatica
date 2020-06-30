#include <stdio.h>
#include <stdlib.h>

void prendi_vett(int *vett, int dim);
void stampa_vett(int *vett, int dim);
void selection(int *vett, int dim);


int main(){
	int dim;
  	int *VETTORE;

	printf("Da quanti elementi vuoi che il vettore sia formato: ");
	scanf("%d", &dim);

	VETTORE=(int*)malloc(dim*sizeof(int));

    prendi_vett(VETTORE, dim);
    stampa_vett(VETTORE, dim);
    selection(VETTORE,dim);
    stampa_vett(VETTORE, dim);

	system("pause");
	return 0;
}


void prendi_vett(int *vett, int dim){
	int i=0;
	while(i<dim){
			printf("Inserisci l'elemento n%d: ",i+1);
			scanf("%d",&vett[i]);

			i++;

		}
}


void stampa_vett(int *vett, int dim){
	int i=0;
	printf("Il vettore e':\n");
	while(i<dim){
		printf("%d ",vett[i]);

		i++;
	}
	printf("\n");
}


void selection(int *vett, int dim){
	int j,k,minimo;
	int temp;

	for(j=0; j<dim-1; j++){

		minimo=j;

	for(k=j+1; k<dim; k++){
		if(vett[k]<vett[minimo]){
			minimo=k;
		}
		temp=vett[minimo];
		vett[minimo]=vett[j];
		vett[j]=temp;
	}
}
}







