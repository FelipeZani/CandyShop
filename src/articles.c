#include "candyshop.h"

void genArticle( char * name, int reference_id,int quantity, float price, char size)
{
	FILE * file= fopen("./articles/articles.txt", "a");
	if(file == NULL)
	{
		printf("ERROR opening the file");
		exit(-1);
	}
	fprintf(file, "%s %d %2.f %c \n", name, reference_id, price,size);
	fclose(file);
}

Article * uploadArticles(FILE farticles, Article * products, int nb_articles)
{
	int count=0;
	
	char buffer[100];
	
	while(count<nb_articles)
	{
		fscanf(farticles,"%s",buffer);
		(products+count)->name=malloc(sizeof(char)*strlen(buffer)+1);
		
		IsAllocated(products+count);
		
		strcpy((products+count)->name,buffer)
		memset(buffer,0,strlen(buffer));
		
		fscanf(farticles, "%d %d %f %c",(products+count)->reference_ID, (products+count)->quantity, (products+count)->price, (products+count)->size);
		count++;
		printf("%s", products[0].name);
	}
	return products;
}

