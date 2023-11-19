#include "candyshop.h"

Shop * storeSetUp(Shop *store)
{
	
	store = malloc(sizeof(Shop));

	IsAllocated(store);
	int d;
	store->nb_articles = NB_ARTICLES_BEGINNING;
	store->nb_custommers = NB_CUSTOMMER_BEGINNING;
	store->stockmax = MAX_STOCK;
	store->products = malloc(sizeof(Article) * store->nb_articles);	
	IsAllocated(store->products);
	
	store->products= uploadArticles(store->products, store->nb_articles);


	FILE * file= fopen("./articles/articles.txt", "a");
	FILE * fcustommer = fopen("./custommer/stand.txt","r");
	fseek(fcustommer, 0, SEEK_END);
	if(ftell(file) == 0)
	{	


		genArticle("Mini_Peanut_Butter",'S', 222989, 0,3.5);
		genArticle("Candies_package", 'M',21321244,2, 2);
		genArticle("Sunkist_Fruit_Jam", 'B',12345678,8, 23.4);
		genArticle("Strawberry_jam ", 'B',145678, 4,3.4);
		genArticle("Lolipop_package", 'B',14678, 23,1.4);
		fclose(file);
	}

	if(ftell(fcustommer) == 0 )
		genCustommer("Jorge","O'Neil");	
	
	fclose(fcustommer);
	
	return store;
}

int main()
{	
	int input;
	Shop * store=NULL;
	store = storeSetUp(store);
	system("clear");
	printf("1- Management mode 2-purchase mode "); // put security system here
	scanf(" %d", &input);
	cleanbuffer();
	switch(input)
	{
		case 1:
			management(store);
			break;
		case 2:
			purchase(store);
			break;
		default:
			printf("option not valid, please try again");
		break;
	}



	return 0;
}

