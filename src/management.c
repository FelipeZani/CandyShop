#include "candyshop.h"

void checkStock(Article * products,int nb_articles)
{
	int i=0, count =0;
	while(i<nb_articles && count<=5) // if there're 100 items the stock will go crazy 
	{
		if((products+i)->quantity<= 5 &&(products+i)->quantity > 0 )
		{
			printf(" almost running out of : %s x %d\n",(products+i)->name, (products+i)->quantity );
			count++;
		} else if((products+i)->quantity == 0)
		{
			printf("ran out of: %s\n",(products+i)->name);
		}
		i++;
	}
}
void searchArticle()
{
	printf("Enter the name of the article or ID");
	if (scanf("%d", &input)==1);
	{
		//search by the ID
	}
	else
	{
		//
	}
}
void management(Shop * store)
{
	int i=0, count=0, input;
	Article * products=malloc(sizeof(Article) * store->nb_articles);
	Article * temp=malloc(sizeof(Article) * store->nb_articles);
	
	IsAllocated(products);
	products= uploadArticles(products, store->nb_articles);
	checkStock(products,store->nb_articles);
	//~ while (1)
	printf("Would you like to search the stock of an article 1- yes 2- no");
	scanf("%d", &input);
	switch(input) 
	{
		case 1:
			searchArticle();
			break;
		case 2:
			break;
		default:
			printf("Invalid option try again"); //force the try again option
	}
	//~ free(products);
	//~ fclose(f1);
}
