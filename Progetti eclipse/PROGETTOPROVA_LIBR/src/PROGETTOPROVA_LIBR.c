//definizioni delle funzione i quali prototipi stanno in progettoprova.h
#include <stdlib.h>
#include <stdio.h>


int sommissima(int a, int b){
	int sum;

	printf("inserisci prima a poi b\n");
	scanf("%d",&a);
	scanf("%d",&b);

	sum=a+b;

	printf("la somma e': %d\n",sum);


	system ("pause");
	return sum;
}
