#include <stdio.h>
#include <stdlib.h>

void lettura (FILE *file, char vettore);
void stampa(char vettore);


int main (){
	FILE *file;
	char vettoreriga[100];

	file=fopen("Prova gets.txt","r");

    lettura(file,vettoreriga);
    stampa(vettoreriga);


	system("pause");
	return 0;
}


void lettura (FILE *file, char vettore){
	if(file){
		while(file!=EOF){
			fgets(vettore,100,file);
		}
	}
	else{
		printf("Errore nell'apertura del file.\n");
	}
}


void stampa(char vettore){
	printf("la stringa e': %s\n",vettore);
}
