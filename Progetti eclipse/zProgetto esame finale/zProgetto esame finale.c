//inclusioni di tutte le librerie utili

#include "funzioniutili.h"
#include <string.h>

//prototipi delle funzioni=====================================================================

void visualizza_giocatori (FILE *pfile, GIOCATORE *struttura);
int leggi_righe (FILE *pfile, GIOCATORE *struttura,int *pdim);
void ricerca_nome(FILE *pfile, GIOCATORE *struttura,int *pdim);

void visualizza_menu(FILE *pfile, GIOCATORE *struttura, int *pdim);



//main==========================================

int main (){
	FILE *pfile;
	GIOCATORE *struttura=NULL;
	int dim=0;
	int *pdim=&dim;   //puntatore che punta alla grandezza di dim

	leggi_righe(pfile,struttura,pdim);

	system("pause");

	visualizza_menu(pfile,struttura,pdim);


    fclose(pfile);
	system("pause");
	return 0;
}

//funzioni=============================================================

void visualizza_menu(FILE *pfile, GIOCATORE *struttura,int *pdim){       //visualizza un menu' sul quale effettuare una scelta che riconduce ad ogni altra funzione presente nel programma
	int scelta;

	printf("          -- Selezionare il numero dell'operazione che si desidera effettuare: --\n");
	printf("_______________________________________________________________________________________\n");
	printf("\n");
	printf(" 1. Visualizza giocatori su FILE.\n");
	printf(" 2. Ricerca una persona in elenco per nome e cognome.\n");
	printf(" 3. Ricerca una persona in elenco per ruolo.\n");
	printf(" 4. Visualizza l'elenco completo dei giocatori in ordine alfabetico.\n");
	printf(" 5. Visualizza l'elenco completo dei giocatori per ruolo.\n");
	printf(" 6. Genera squadre per una partita.\n");
	printf(" 7. Aggiungi persone all'elenco.\n");
	printf("\n");
	printf("Effettuare operazione numero: ");

	scanf("%d",&scelta);
	while (scelta<1 || scelta>7){
		printf("Opzione non valida, selezionare una scelta corretta: ");
		scanf("%d",&scelta);
	}

	fflush(stdin);       //pulisce il buffer, perchè la scanf lascia nel buffer lo \n che la gets leggerebbe come valore

	switch(scelta){

	case 1:
		visualizza_giocatori(pfile,struttura);
	break;

	case 2:
		ricerca_nome(pfile,struttura,pdim);
	break;
	}
}

//___________________________________________________________________________________________________________

void visualizza_giocatori(FILE *pfile, GIOCATORE *struttura){                //carica in memoria e stampa il numero di giocatori richiesto

	pfile=fopen("Giocatoriv.txt","r");

		int dim=0;
		int i=0;
		int j=0;

		if(pfile!=NULL){
			printf("Quanti giocatori vuoi visualizzare? ");
				scanf("%d",&dim);
				printf("\n");

				struttura=(GIOCATORE*)malloc(dim*sizeof(GIOCATORE));

				while(i<dim){
							if(!feof(pfile)){
								fscanf(pfile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",struttura[i].cognome,struttura[j].nome,
										struttura[i].genere,struttura[i].email,struttura[i].telefono,struttura[i].ruolo);
								i++;
							}
							else{
								printf(" ---Giocatori presenti in memoria minori di quelli richiesti--- \n");
								dim=i;
							}
					}
						printf("\n");
						while (j<dim){
							printf("%s,%s,%s,%s,%s,%s -",struttura[j].cognome,struttura[j].nome,
										struttura[j].genere,struttura[j].email,struttura[j].telefono,struttura[j].ruolo);
							j++;
							printf("\n");
						}
				}
		else{
	          printf("errore di apertura del file.\n");
		}

		free(struttura);
		fclose(pfile);
		system("pause");
}

//___________________________________________________________________________________________________________

void ricerca_nome (FILE *pfile, GIOCATORE *struttura, int *pdim){

		pfile=fopen("Giocatoriv.txt","r");


	  int i=0;
	  int k=0;
	  char nome[20];
	  char cognome[20];


				if(pfile!=NULL){

					struttura=(GIOCATORE*)malloc(*pdim*sizeof(GIOCATORE));



				while(i<pdim){
					if(!feof(pfile)){
					fscanf(pfile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",struttura[i].cognome,struttura[i].nome,
							struttura[i].genere,struttura[i].email,struttura[i].telefono,struttura[i].ruolo);
				       	i++;
									}

								}
											}
					else{
					          printf("errore di apertura del file.\n");
						}
				printf("\n");

			printf("Inserisci il nome della persona da ricercare: ");
			fgets(nome,20,stdin);
			nome[strcspn(nome,"\n")]=0;                        //elimina nel buffer lo \n dato dall fgets, altrimenti l'input dato sarebbe "nome\n" (dato l'enter per confermare)
			printf("Inserisci il cognome della persona da ricercare: ");
			fgets(cognome,20,stdin);
			cognome[strcspn(cognome, "\n")] = 0;

					while(k<pdim){
					if(strcmp(cognome,struttura[k].cognome)==0 && strcmp(nome,struttura[k].nome)==0){


					    printf("La persona persona ricercata e' in elenco: ");
						printf("%s,%s,%s,%s,%s,%s\n",struttura[k].cognome,struttura[k].nome,
								struttura[k].genere,struttura[k].email,struttura[k].telefono,struttura[k].ruolo);
						k=pdim;
							}
					else{

						k++;

					}


				}

					if(k==pdim){
											printf("persona non in elenco\n");
										}


				fclose(pfile);
				system("pause");
		}











int leggi_righe (FILE *pfile, GIOCATORE *struttura,int *pdim){
	pfile=fopen("Giocatoriv.txt","r");
	char c;
	int cont=1;

	if(pfile!=NULL){
		while(!feof(pfile))
				{
				  c=fgetc(pfile);
				  if(c=='\n')
				  {
				    cont++;
					  }
				}
	}

	*pdim=cont;       //dim sarà uguale a cont
	fclose(pfile);
	return *pdim;

}





