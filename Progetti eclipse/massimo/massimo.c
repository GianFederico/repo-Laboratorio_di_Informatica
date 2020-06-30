#include <stdio.h>
#include <stdlib.h>

int massimo(int a,int b);

int main(){
	int x,y;

	massimo(x,y);
	system("pause");
	return 0;
}

int massimo(int a, int b){
	printf("inserisci il primo valore: ");
	scanf("%d",&a);
	printf("inserisci il secondo valore: ");
	scanf("%d",&b);

	if(a<b){
		printf("il valore maggiore e': %d\n",b);
	}
	else{
		printf("il valore maggiore e': %d\n",a);
	}

 return 0;
}
