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
	while(count<nb_articles)
	
	return products;
}

