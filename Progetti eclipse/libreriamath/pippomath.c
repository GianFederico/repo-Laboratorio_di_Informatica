#include <stdio.h>
#include <stdlib.h>

int massimo(int a, int b){
	if(a<b){
		printf("il valore maggiore e': %d\n",b);
	}
	else{
		printf("il valore maggiore e': %d\n",a);
	}
 return 0;
}

//=========================================================================

int minimo(int a, int b){
	if(a>b){
		printf("il valore minore e': %d\n",b);
	}
	else{
		printf("il valore minore e': %d\n",a);
	}
 return 0;
}

//=========================================================================

int somma(int a, int b){
	int somma;
	somma= a+b;
	printf("la somma dei due valore e': %d\n", somma);
	return 0;
}

//=========================================================================

int sottrazione(int a, int b){
	int diff;
	diff= a-b;
	printf("la differenza dei due valore e': %d\n", diff);
	return 0;
}

//=========================================================================

int prodotto(int a, int b){
	int prod;
	prod= a*b;
	printf("il prodotto dei due valore e': %d\n", prod);
	return 0;
}

//=========================================================================

int quadrato (int a, int b){
	int quad1;
	int quad2;
	quad1=a*a;
	quad2=b*b;
	printf("il quadrato del primo numero e': %d\n", quad1);
	printf("il quadrato del secondo valore e': %d\n", quad2);
	return 0;
}

//=========================================================================


