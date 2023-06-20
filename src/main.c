#include "candyshop.h"

Shop * storeSetUp(Shop *store)
{
	store= malloc(sizeof(Shop));
	store->nb_articles=NB_ARTICLES_BEGINNING;
	store->nb_custommers=NB_CUSTOMMER_BEGINNING;
	store->stockmax=#define MAX_STOCK;

	
	genArticle("Mini_Peanut_Butter",'S', 222989, 0,3.5);
	genArticle("Candies_package", 'M',21321244,2, 2);
	genArticle("Sunkist_Fruit_Jam", 'B',12345678,8, 23.4);
	genArticle("Strawberry_jam ", 'B',145678, 4,3.4);
	genArticle("Lolipop_package", 'B',14678, 23,1.4);
	
	genCustommer("Jorge","O'Neil");
	return store;
}

int main()
{	
	int input;
	Shop * store=NULL;
	
	store = storeSetUp(store);
	printf("Management mode or purchase mode"); // put security system here
	scanf("%d", &input);
	
	switch(input)
	{
		case 1:
			management(store);
			break;
		case 2:
			addArticle(store->products);
			break;
		default:
			printf("option not valid, please try again");
		break;
	}


	
	return 0;
}

