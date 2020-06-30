#include <stdio.h>
#define MAX_PEOPLE_SIZE 200


typedef struct people
{
  char code[10];
  char first_name[50];
  char last_name[50];
  long telephone;
} PEOPLE;


int main()
{
   FILE *fp = fopen("example.txt", "r");
   int i = 0;
   PEOPLE people[MAX_PEOPLE_SIZE];
   int size;

   while (!feof(fp)) {
       read(people, i, fp);
       i++;
   }
   size = i;

   for (i = 0; i < size; ++i)
     printf("%s, %s, %s, %ld\n", people[i].code, people[i].first_name,
	    people[i].last_name, people[i].telephone);


   fclose(fp);
}

int read(PEOPLE people[], int n_p, FILE* fp){
   char temp;

   if(fp==NULL){
       printf("Error\n");
       return -1;
   }
   fscanf(fp,"%s %s %s %ld\n", people[n_p].code, people[n_p].first_name,
	  people[n_p].last_name, &people[n_p].telephone);
}
