#include <stdio.h>
#include <stdlib.h>

void trova_elem (FILE *pfile, int *vettore, int dim);

int main(){
	int dim;
    int scelta;
	int *vettore;
	FILE *pfile;
	int dimdue;

	printf("inserisci la dimensione del vettore:");
	scanf("%d",&dim);

	vettore=(int*)malloc(dim*sizeof(int));

	printf("sicuro? 1=no, modifica   2=si, mantieni\n");
	scanf("%d",&scelta);
	if(scelta==1){
		printf("reinserisci la dimensione: ");
		scanf("%d",&dim);

		realloc(vettore,dim);
	}

	system("pause");


    trova_elem(pfile,vettore,dim);

	system("pause");
	return 0;
}



void trova_elem (FILE *pfile, int *vettore, int dim){
	int elem;
	int i=0;
	int j=0;
	int val;
	int posiz;
	int valore;
	int k=0;

	pfile=fopen("C:\\Users\\admin\\Desktop\\insieme.txt","r");

	    if(pfile!=NULL){
	    	if(!feof(pfile))
	   	 		while(i<dim){
	    		fscanf(pfile,"%d",&val);
	    		vettore[i]=val;
	    		i++;
	        }

	    	else{
	    		printf("fine file");
	    	}

	    }

	    else{
	    	printf("errore con il file");
	    }


	    printf("il vettore e': ");
	    while(j<dim){
	    	  	printf("%d ",vettore[j]);
	    	j++;
	    }

    printf("\n");

	printf("inserisci l'elemento da cercare: ");
	scanf("%d",&elem);


	posiz=dim/2;

	valore=vettore[posiz];

	if(elem<=valore){
		i=0;
		while(i<=posiz){
			if(vettore[i]==elem){
				printf("elemento trovato\n");
				i++;
			}
			else{
				i++;
				if(i==posiz){
								printf("elemento non presente\n");
							}
			}

		}

	}
	else{
		i=posiz;
		while(i<=dim){
					if(vettore[i]==elem){
						printf("elemento trovato\n");
						i++;
					}
					else{
						i++;
						if(i==dim){
												printf("elemento non presente\n");
											}
					}

				}

							}

	fclose(pfile);

	pfile=fopen("C:\\Users\\admin\\Desktop\\insieme2.txt","w");

	fprintf(pfile,"il vettore e': ");
		    while(k<dim){
		    	  	fprintf(pfile,"%d ",vettore[k]);
		    	k++;
		    }





}
