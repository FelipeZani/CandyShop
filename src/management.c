#include "candyshop.h"

void management(Shop * store)
{
	int i=0;
	Article * products=malloc(sizeof(Article) * store->nb_articles);
	Article * temp=malloc(sizeof(Article) * store->nb_articles);
	
	IsAllocated(products);
	products= uploadArticles(products, store->nb_articles);
	
	for(int i = 0; i<nb_)
	
	//~ free(products);
	//~ fclose(f1);
}
