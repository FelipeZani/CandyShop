#include "candyshop.h"

void genArticle( char * name, char size, int reference_id,int quantity, float price)
{
	FILE * file= fopen("./articles/articles.txt", "a");
	if(file == NULL)
	{
		printf("ERROR opening the file");
		exit(-1);
	}
	fprintf(file, "%s %c %d %d %f\n", name,size, reference_id,quantity, price);
	fclose(file);
}

Article * uploadArticles(Article * products, int nb_articles)
{
	FILE * farticles=fopen("./articles/articles.txt", "r");
	IsAllocated(farticles);
	int count=0;
	
	char buffer[100];
	
	while(count<nb_articles)
	{
		fscanf(farticles,"%s",buffer);
		(products+count)->name=malloc(sizeof(char)*strlen(buffer)+1);
		
		IsAllocated(products+count);
		
		strcpy((products+count)->name,buffer);
		memset(buffer,0,strlen(buffer));
		
		fscanf(farticles," %c %d %d %f",&(products+count)->size,&products[count].reference_ID, &(products+count)->quantity, &(products+count)->price);
		count++;
	}
	
	return products;
}

