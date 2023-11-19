#include "candyshop.h"

void management(Shop * store)
{
	//create allocation fonction
	int i=0, count=0, input;

	checkStock(store->products,store->nb_articles);
	printf("Would you like to 1) search the stock of an article  2) Add new articles to the stock ");
	scanf("%d", &input);
	switch(input) 
	{
		case 1:
			searchArticle(store->nb_articles, store->products);
			break;
		case 2:
			addArticle(store->products,store->nb_articles,MAX_STOCK);
			break;
		default:
			printf("Invalid option try again"); //force the try again option
	}
}

void addArticle(Article * products,int nb_articles, int maxItems)
{
	int on_off=1, index=-1, add_articles=0;
	char buffer[MAX_LIMIT];

	cleanbuffer();
	do
	{
		
		printf("\nInput the name of the article: ");
		fgets(buffer,MAX_LIMIT, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		
		if((index=isInTheStore(buffer, products, nb_articles))==-1)
		{
			printf("\nInvalid article name, only article's already present in the store can be added\ninput the name again");
			memset(buffer,0,strlen(buffer));
		}
		else
		{

			printf("\nname: %s quantity: %d ", products[index].name,products[index].quantity);
			printf("\nhow many would you to add new products would you like to add?");
			scanf("%d", &add_articles);
			cleanbuffer();
			products[index].quantity+=add_articles;
			if(products[index].size=='S')
			{
				printf("\nfor small products you can only have 10 products stocked");
				if(products[index].quantity>10)
					{
						products[index].quantity=10;
						printf("\nlimit exceeded");
					}
			}
			printf("\nname: %s quantity: %d", products[index].name,products[index].quantity);
		}
		printf("\nWould you like to add a new article press 0 for no");
		fgets(buffer, MAX_LIMIT, stdin);
        sscanf(buffer, "%d", &on_off);
		if(on_off!=0)
		{
			on_off=1, index=-1, add_articles=0;
			memset(buffer,0,strlen(buffer));
			
		}
	}while(on_off);
	saveArticles(products,nb_articles);
	
}
