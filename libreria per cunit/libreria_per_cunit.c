#include <stdio.h>
#include <stdlib.h>
#include "header_per_cunit.h"
#include <string.h>

//=============================================================================
void menu(){
	int cont_tracce;
	int scelta_menu;
	int cont_pl;
	FILE *pfile;                //puntatore al file
	BRANO *struttura;			//struttura (campi: artista,titolo,genere,stelle)
	PLAYLIST *megastruct;		//struct di struct (unico campo: BRANO iperstruct)

	int scelta;

		printf("            -- Selezionare l'operazione che si desidera effettuare --\n");
		printf("_______________________________________________________________________________________\n");
		printf("\n");
		printf(" 1. Visualizza l'elenco dei brani presenti su FILE.\n");
		printf(" 2. Ricerca un brano per titolo.\n");
		printf(" 3. Aggiungi nuovo brano su FILE.\n");
		printf(" 4. Visualizza l'elenco delle playlist presenti su FILE.\n");
		printf(" 5. Crea una nuova playlist.\n");
		printf(" 6. Visualizza brani per numero di stelle.\n");
		printf("\n");
		printf("Effettuare operazione numero: ");

		scanf("%d",&scelta);
			while(scelta<1 || scelta>6){
				printf("Numero selezionato non valido; Riprovare: ");
				scanf("%d",&scelta);   //serve & per l'indirizzo di memoria dove salvare il valore della variabile int
			}

			fflush(stdin);

	switch(scelta){

		case 1:
/*funzione*/    cont_tracce=conta_righe(pfile,cont_tracce);
/*procedura*/   visualizza_brani(pfile,struttura,cont_tracce);
         	    break;

		case 2:
/*funzione*/	cont_tracce=conta_righe(pfile,cont_tracce);
/*procedura*/	ricerca_brano(pfile,struttura,cont_tracce);
				break;


		case 3:
/*procedura*/	aggiungi_brano(pfile,struttura);
				break;

		case 4:
/*funzione*/	conta_playlist(pfile,cont_pl);
/*procedura*/	visualizza_playlist(pfile);
				break;

		case 5:
/*funzione*/	cont_tracce=conta_righe(pfile,cont_tracce);
/*procedura*/	componi_playlist(pfile,struttura, megastruct, cont_tracce);
				break;
		case 6:
/*funzione*/	cont_tracce=conta_righe(pfile,cont_tracce);
/*procedura*/   ordina_brani(pfile,struttura,cont_tracce);
				break;
		}

	 printf("____________________________________________________\n");
	 printf("\n");

	 printf("Vuoi tornare al menu o preferisci uscire? Premi:\n-1 per tornare al menu.\n-Qualsiasi altro tasto per uscire.\n");
		scanf("%d",&scelta_menu);
				if(scelta_menu==1){
					system("cls");
					menu();
				}
				else{
					printf("Bye-bye.\n");
				}
}

//=============================================================================
int conta_playlist(FILE *pfile, int cont_pl){
	int i=0;
	char c;


	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\elencopl.txt","r");
	while((c=fgetc(pfile))!=EOF){           //finchè la fgetc non arriva a fine del file
		if(c=='\n')                         //se c è uguale a \n   (conta quanti \n ci sono nel file)
			i++;
	}

	cont_pl=i;
	return cont_pl;
}

//=============================================================================
void visualizza_brani (FILE *pfile, BRANO *struttura, int cont_tracce){

	int dim=0;
	int i=0;
	int j=0;

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","r");

	if(pfile!=NULL){						//se il puntatore a file è diverso NULL, quindi se non c'è un errore di apertura
		printf("Quanti brani vuoi visualizzare?\n");
		printf("Ti ricordo che puoi visualizzarne al massimo quanti ce ne sono nel file (%d): ",cont_tracce);

		scanf("%d",&dim);
				while(dim<1 || dim>cont_tracce){
						printf("Quantità selezionata non valida; Riprovare: ");
						scanf("%d",&dim);
				}

     struttura=(BRANO*)malloc(dim*sizeof(BRANO));  //allocazione dinamica della memoria


     	 	 	while(i<dim){              //la formattazione della fscanf prende "tutto quello che non è tab, fino al tab,
     				if(!feof(pfile)){      //per il primo campo, lo stesso per gli altri, tranne l'ultimo che è int e non ha tab
     					fscanf(pfile,"%[^\t]\t%[^\t]\t%[^\t]\t%d",struttura[i].artista,struttura[i].titolo,
     							struttura[i].genere,&struttura[i].stelle);
     					i++;
     				}
     			}

     	printf("\n");
		printf("TITOLO,  ARTISTA,  GENERE,  STELLE\n");
		printf("\n");

				while (j<dim){
					printf("%s, %s, %s, %dstelle.",struttura[j].artista,struttura[j].titolo,   //visualizza a video i brani
							struttura[j].genere,struttura[j].stelle);
					j++;
					printf("\n");
				}
	}
	else{
		printf("Errore di apertura.\n");
	}

	free(struttura);     //libera la memoria allocata
    fclose(pfile);       //chiude il file
    printf("____________________________________________________\n");
    printf("\n");


}

//=============================================================================

void ricerca_brano (FILE *pfile, BRANO *struttura, int cont_tracce){

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","r");
	int i=0;
	int j=0;
	char nome[30];

	struttura=(BRANO*)malloc(cont_tracce*sizeof(BRANO));

 while(i<cont_tracce){              //la formattazione della fscanf prende "tutto quello che non è tab, fino al tab,
	    	if(!feof(pfile)){      //per il primo campo, lo stesso per gli altri, tranne l'ultimo che è int e non ha tab
			 	 	fscanf(pfile,"%[^\t]\t%[^\t]\t%[^\t]\t%d",struttura[i].artista,struttura[i].titolo,
			 	 	 		struttura[i].genere,&struttura[i].stelle);
			 	 	 i++;
			 }
    }

	fflush(stdin);    //pulisce il buffer, perchè la scanf lascia nel buffer lo \n che la gets leggerebbe come valore

	printf("Inserisci il titolo del brano che stai cercando: ");
		 	 	 	 gets(nome);

		  while(j<cont_tracce){
			  if(strcmp(nome,struttura[j].titolo)==0){       //se la comparazione delle stringhe è 0, sono uguali.
				  printf("Brano in elenco: ");
				  printf("%s, %s, %s, %dstelle.\n", struttura[j].artista, struttura[j].titolo, struttura[j].genere, struttura[j].stelle);
				  j=cont_tracce;    //j=cont_tracce fa uscire dal while senza entrare nell'else
			  }
			  else{
				 j++;
				    if(j==cont_tracce){
				    printf("Brano NON in elenco.\n");
				    }
			  }
		  }

	  free(struttura);      //libera la memoria allocata
	  fclose(pfile);        //chiude il file
	  printf("____________________________________________________\n");
	  printf("\n");


}

//=================================================================================

int aggiungi_brano(FILE *pfile, BRANO *struttura){

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","a");
	BRANO traccia;    //definisco la struttura nella quale verranno memorizzati gli input da tastiera

	if(pfile!=NULL){

		if(!feof(pfile)){

			printf("\n");
			fflush(stdin);    //pulisce il buffer

		printf("Inserisci il titolo del brano:\n");
			gets(traccia.titolo);
			printf("\n");
			fflush(stdin);
				printf("Inserisci l'artista del brano:\n");
						gets(traccia.artista);
						printf("\n");
						fflush(stdin);
						printf("Inserisci il genere del brano:\n");
									gets(traccia.genere);
									printf("\n");
									fflush(stdin);
									printf("Inserisci le stelle assegnate del brano:\n");
												scanf("%d",&traccia.stelle);

												while(traccia.stelle<0 || traccia.stelle>5){
																printf("Numero di stelle digitato non valido (MIN:0 MAX:5); Riprovare: ");
																scanf("%d",&traccia.stelle);
												}

												printf("\n");

		fprintf(pfile,"%s\t%s\t%s\t%d\n",traccia.artista,traccia.titolo,traccia.genere,traccia.stelle);

		}
		return 0;
	}
	else{
		printf("Errore di apertura.\n");

		return 1;
	}

 		      fclose(pfile);
 		      printf("____________________________________________________\n");
 		      printf("\n");

}

//================================================================

int conta_righe(FILE *pfile, int cont_tracce){
	int i=0;
	char c;


	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","r");
	while((c=fgetc(pfile))!=EOF){           //finchè la fgetc non arriva a fine del file
		if(c=='\n')                         //se c è uguale a \n   (conta quanti \n ci sono nel file)
			i++;
	}

	cont_tracce=i;
	return cont_tracce;
}
//================================================================

int visualizza_playlist(FILE *pfile){

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\elencopl.txt","r");

	char playlist[51];

	printf("Playlist presenti su FILE:\n");
	printf("\n");

	if(pfile!=NULL){
		while(!feof(pfile)){
              fscanf(pfile,"%[^\n]\n",playlist); //tutto quello che c'è, escluso lo \n, fino allo \n

              printf("-%s\n",playlist);
		}
		return 0;
	}
		else{
				printf("Errore di apertura.\n");
				return 1;
			}
	 printf("\n");
	 fclose(pfile);
	 		      printf("____________________________________________________\n");
	 		      printf("\n");
}

//================================================================

void componi_playlist(FILE *pfile, BRANO *struttura, PLAYLIST *megastruct, int cont_tracce){

	char path[251];
	char nome[51];
	char nomefile [51];
	int dim;
	int n=0;
	int i=0;
	int j=0;

	printf("Inserisci il nome della playlist: ");
	gets(nomefile);

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\elencopl.txt","a+");

		if(pfile!=NULL){

			fprintf(pfile,"%s\n",nomefile);

		}
		else{
			printf("Errore di apertura.\n");
		}

		fclose(pfile);

	printf("Inserisci il percorso della playlist che vuoi creare, con il relativo nome: ");
	gets(path);


	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","r");

			if(pfile!=NULL){						//se il puntatore a file è diverso NULL, quindi se non c'è un errore di apertura

			struttura=(BRANO*)malloc(cont_tracce*sizeof(BRANO));  //allocazione dinamica della memoria


					while(i<cont_tracce){      //la formattazione della fscanf prende "tutto quello che non è tab, fino al tab,
						if(!feof(pfile)){      //per il primo campo, lo stesso per gli altri, tranne l'ultimo che è int e non ha tab
							fscanf(pfile,"%[^\t]\t%[^\t]\t%[^\t]\t%d",struttura[i].artista,struttura[i].titolo,
									struttura[i].genere,&struttura[i].stelle);
							i++;
						}
					}

				printf("\n");
				printf("Tracce disponibili da inserire nella playlist: \nTITOLO,  ARTISTA,  GENERE,  STELLE\n");
				printf("\n");

						while (j<cont_tracce){
							printf("%s, %s, %s, %dstelle.",struttura[j].artista,struttura[j].titolo,
									struttura[j].genere,struttura[j].stelle);
							j++;
							printf("\n");
						}
			}
			else{
				printf("Errore di apertura.\n");
			}

	                  j=0;


			fclose(pfile);

		    fflush(stdin);    //pulisce il buffer

		    printf("___________________________________________________________\n");
			printf("Quanti brani vuoi aggiungere alla playlist?\n ");
			scanf("%d",&dim);
			fflush(stdin);

			megastruct=(BRANO*)malloc(cont_tracce*sizeof(BRANO));

			pfile=fopen(path,"a+");

			if(pfile!=NULL){

			while(n<dim){

				 printf("Inserisci il titolo del brano che vuoi aggiungere alla nuova playlist: ");
				 gets(nome);

				 	 j=0;

				while(j<cont_tracce){
					  if(strcmp(nome,struttura[j].titolo)==0){
						  printf("Brano in elenco :)\n ");

						  megastruct[n].iperstruct=struttura[j];

						  struttura[j].stelle=struttura[j].stelle +1;

						  if(struttura[j].stelle>5){

							  struttura[j].stelle=5;
						  }

						  fprintf(pfile,"%s, %s, %s, %dstelle.\n", struttura[j].artista, struttura[j].titolo, struttura[j].genere, struttura[j].stelle);

						  j=cont_tracce;
										  }
					  else{
							 j++;
								if(j==cont_tracce){
								printf("Brano NON in elenco.\n-NON inserito correttamente-\n");
											    	}
						  }
				 }
			n++;
			}
		}
			else{
			printf("Errore di apertura.\n");
		     }

			fclose(pfile);
			free(struttura);
			free(megastruct);


			pfile=fopen(path,"r");

			int c;

			printf("\n");
			printf("\n");
			printf("Playlist creata:\n");


			if (pfile!=NULL) {
			    while ((c = getc(pfile)) != EOF)  //c è int perchè EOF vale -1
			        putchar(c);
			    fclose(pfile);
			}

}

//=================================================================================================
int ordina_brani (FILE *pfile, BRANO *struttura, int cont_tracce){


	int i=0;
	int j=0;
	int pass=0;
	BRANO temp;

	printf("\n");
	printf("- LISTA DEI BRANI ORDINATI PER NUMERO DI STELLE:\n");

	pfile=fopen("C:\\Users\\admin.GIANFEDERICO-PC\\Desktop\\Nuova cartella\\Progetto esame aprile\\file txt\\tracce.txt","r");

	if(pfile!=NULL){						//se il puntatore a file è diverso NULL, quindi se non c'è un errore di apertura


     struttura=(BRANO*)malloc(cont_tracce*sizeof(BRANO));  //allocazione dinamica della memoria


		while(i<cont_tracce){              //la formattazione della fscanf prende "tutto quello che non è tab, fino al tab,
			if(!feof(pfile)){      //per il primo campo, lo stesso per gli altri, tranne l'ultimo che è int e non ha tab
				fscanf(pfile,"%[^\t]\t%[^\t]\t%[^\t]\t%d",struttura[i].artista,struttura[i].titolo,
						struttura[i].genere,&struttura[i].stelle);
				i++;
			}
		}

			while(pass<cont_tracce){										//prima li ordina per stelle
				i=0;
				while(i<cont_tracce){
					if(struttura[i].stelle>struttura[i+1].stelle){
						temp=struttura[i];
						struttura[i]=struttura[i+1];
						struttura[i+1]=temp;
					}
					i++;
				}
				pass++;
			}

			pass=0;
			i=0;

			while(pass<cont_tracce){										//poi a parità di stelle, ordina per ordine alfabetico
					i=0;
					while(i<cont_tracce){
						if(struttura[i].stelle==struttura[i+1].stelle){                //se hanno le stesse stelle
							if(strcmp(struttura[i].titolo,struttura[i+1].titolo)>0){   //se strcmp restituisce >0, cioè se struttura[i].titolo
							temp=struttura[i];										   //viene alfabeticamente dopo struttura[i+1].titolo
							struttura[i]=struttura[i+1];
							struttura[i+1]=temp;
							}
						}
						i++;
					}
					pass++;
				}

     	 	 	printf("\n");
		printf("TITOLO,  ARTISTA,  GENERE,  STELLE\n");

				while (j<cont_tracce){
					printf("%s, %s, %s, %dstelle.",struttura[j].artista,struttura[j].titolo,  //stampa la struttura ordinata
							struttura[j].genere,struttura[j].stelle);
					j++;
					printf("\n");
				}
				return 0;
	}
	else{
		printf("Errore di apertura.\n");
		return 1;
	}

	free(struttura);  //libera la memoria allocata
    fclose(pfile);    //chiude il file
    printf("\n");

}


