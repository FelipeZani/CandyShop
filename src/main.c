#include "candyshop.h"

void storeSetUp(Shop store)
{
	*(store.nb_articles)=NB_ARTICLES_BEGINNING;
	*(store.nb_custommers)=NB_CUSTOMMER_BEGINNING;
	
	genArticle("mini Peanut Butter", 222989, 5,3.5, 'S');
	genArticle("Candies package", 21321244,2, 2, 'M');
	genArticle("Sunkist Fruit Jam", 12345678,8, 23.4, 'B');
	genArticle("strawberry jam ", 145678, 23.4,3, 'B');
	genArticle("Lolipop package", 14678, 23.4,1, 'B');
	
	genCustommer("Jorge","O'Neil");
}

int main()
{	
	int loop =1;
	int input;
	Shop store;
	
	storeSetUp(store);
	
	
	while(loop)
	{
		printf("Management mode or purchase mode"); // put security system here
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				management();
				break;
			case 2:
				break;
			default:
				printf("Not valid option, please try again");
			break;
		}
	}
	
	
	
	return 0;
}

