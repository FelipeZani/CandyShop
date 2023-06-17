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
			printf(" ran out of: %s\n",(products+i)->name);
		}
		i++;
	}
}
void searchArticle(int nb_articles, Article * products)
{
	char buffer[100];
	int input,i=0, found=0, on_off=1;
	printf("Enter the name of the article or ID: ");
	while(on_off)
	{
		if(scanf("%d", &input)==1)
		{

			while(i<nb_articles&&found==0)
			{
				if(products[i].reference_ID == input)
				{
					printf("\n product: %s quantity: %d",products[i].name,products[i].quantity);
					found=1;
					on_off=0;
				}
			}
			if(found==0)
				printf("\nProduct not found, insert its ID again");
		}	
		else
		{
			sprintf(buffer,input);
			
		}
	}
}
void management(Shop * store)
{
	int i=0, count=0, input;
	store->products=malloc(sizeof(Article) * store->nb_articles);	
	IsAllocated(store->products);
	store->products= uploadArticles(store->products, store->nb_articles);
	checkStock(store->products,store->nb_articles);
	//~ while (1)
	printf("Would you like to search the stock of an article 1- yes 2- no");
	scanf("%d", &input);
	switch(input) 
	{
		case 1:
			searchArticle(store->nb_articles, store->products);
			break;
		case 2:
			break;
		default:
			printf("Invalid option try again"); //force the try again option
	}
	//~ free(products);
	//~ fclose(f1);
}
