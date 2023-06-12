#include "candyshop.h"

void management(int nb_artc)
{
	int i=0;
	Article * products=malloc(sizeof(Article)*nb_articles);
	FILE * f1=fopen("./articles/articles.txt", "r");
	IsAllocated(f1);
	IsAllocated(products);
	products= uploadArticles(f1,products, nb_articles, nb_articles);
	
	free(products);
	fclose(f1);
}
