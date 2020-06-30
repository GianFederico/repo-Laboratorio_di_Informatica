#include <stdio.h>
#include <stdlib.h>
#include "pippomath.h"



int main(){
	int x,y;
	int ris;
	printf("inserisci il primo valore: ");
	scanf("%d",&x);
	printf("inserisci il secondo valore: ");
	scanf("%d",&y);

	somma(x,y);
	prodotto(x,y);
	massimo(x,y);
	minimo(x,y);
	quadrato(x,y);

	ris=x+y+costanteprova;
	printf("%d+%d+%d=%d\n", x,y,costanteprova,ris);


	system("pause");
	return 0;
}
