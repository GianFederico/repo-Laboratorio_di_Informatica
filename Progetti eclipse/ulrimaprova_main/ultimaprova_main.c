#include <stdio.h>
#include<stdlib.h>
#include "ultimaprova_libr.h"
#define DIM 15

int main (){
	int vett[DIM]={2,6,4,9,1,6,3,7,0,4,6,5,6,6,6};

 ordina_vett(vett,DIM);
 stampa_vett(vett,DIM);

	system("pause");
	return 0;
}
