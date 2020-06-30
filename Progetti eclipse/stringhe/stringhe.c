#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inverti_stringa(char *stringa);
void conta_stringa(char *stringa);
void conta_vocali(char *stringa);


int main (){
	char mex[81];
	char mexdue[38];
	int lungh;
	int lunghdue;
	printf("scrivi una stringa:");
	gets(mex);
	printf("scrivi un'altra stringa:");
	gets(mexdue);
	printf("la stringa appena inserita e': ");
	puts(mex);

	lungh=strlen(mex);
	printf("la lunghezza della prima stringa e': %d caratteri\n",lungh);

	lunghdue=strlen(mexdue);
		printf("la lunghezza della seconda stringa e': %d caratteri\n",lunghdue);

	system ("pause");
	inverti_stringa(mex);
	printf("la prima stringa invertita e': ");
	puts(mex);
	inverti_stringa(mexdue);
	printf("la seconda stringa invertita e': ");
	puts(mexdue);

	system("pause");
	conta_stringa(mex);
	conta_vocali(mex);


	system ("pause");
	return 0;
}


void inverti_stringa(char *stringa){
	int i=0;
	int j=strlen(stringa)-1;
	char temp;

	while(i<strlen(stringa)/2){
		temp=stringa[i];
		stringa[i]=stringa[j];
		stringa[j]=temp;
		 i++, j--;
	}
}


void conta_stringa(char *stringa){
	int i=0;
	int cont=0;
	while(stringa[i]!='\0'){
			cont=cont+1;
			i++;
		}	printf("la lunghezza e': %d\n", cont);

}

void conta_vocali(char *stringa){
	int i=0;
	int cont=0;
	while(stringa[i]!='\0'){
			if (stringa[i]=='a' || stringa[i]=='e' || stringa[i]=='i' ||stringa[i]=='o' || stringa[i]=='u'){
				cont=cont+1;
				i++;
			}
			else{
				i++;}
		}	printf("le volcali presenti sono: %d\n", cont);
}








