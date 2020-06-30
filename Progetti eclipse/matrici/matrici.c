#include <stdio.h>
#include <stdlib.h>

int main(){
//matrice statica
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	int k=0;
	int h=0;

	int somma=0;

	int righe;
	int colonne;
	int l=0;

	int matrice [3][3];

	int **matricedue;


	for (i=0; i<3;i++){
		for(j=0; j<3; j++){
			printf("inserisci l'elemento: ");
			scanf("%d",&(matrice[i][j]));
		}
	}

	for (i=0; i<3;i++){
			for(j=0; j<3; j++){
				printf("%d ", matrice[i][j]);
				printf("\n");
				}
		}

	system("pause");

//matrice con allocazione dinamica della memoria

	printf("Inserisci il numero di righe per la nuova matrice: ");
	scanf("%d",&righe);
	printf("Inserisci il numero di colonne per la nuova matrice: ");
	scanf("%d",&colonne);

	matricedue=(int **)malloc(sizeof(int *) *righe);
	while(l<righe){

		matricedue[l]=(int *)malloc(sizeof(int)*colonne);

		l++;

	}


	for (m=0; m<righe;m++){
			for(n=0; n<colonne; n++){
				printf("inserisci l'elemento: ");
				scanf("%d",&(matricedue[m][n]));
			}
		}

		for (m=0; m<righe;m++){
				for(n=0; n<colonne; n++){
					printf("%d ", matricedue[m][n]);
					printf("\n");
					}
			}

	system("pause");

//somma degli elementi della matrice ------NON FUNGE------

	while(k<=righe){
		while (h<=colonne){
			somma=somma+matrice[k][h];
			h++;
		}
		k++;
	}

	printf("la somma e': %d ", somma);

    system("pause");
	free(matricedue);
	return 0;
}


