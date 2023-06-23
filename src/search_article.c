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
void searchArticle(int nb_articles, Article * products)//create a management fonct
{
	int input=-1, found=0, on_off=1, idproduct=-1;
	int toleave;
	char buffer[MAX_LIMIT];
	
	while (on_off)
	{
		while(input <= 0 || input >= 3)
		{
			printf("\nWould you like to choose by 1) number ID or 2)the name:");
			scanf(" %d", &input);
			if(input <= 0 || input >= 3)
				printf("\nIncorret format, please insert the option again\n");
		}
		cleanbuffer();
		if(input == 1)
		{	
			while(found==0)
			{
				while(idproduct<=0)
				{
					printf("Enter the ID number of the product: ");
					scanf(" %d",&idproduct);
					cleanbuffer();
					if(idproduct<=0)
						printf("invalid format, please try again\n");
				}
				for(int i = 0;i<nb_articles;i++)
				{
					if(products[i].reference_ID ==idproduct)
					{
						printf("\n product: %s quantity: %d",products[i].name,products[i].quantity);
						found=1;
						
					}
				}
				if(found==0)
				{
					printf("\nArticle not found");
				}
				if((on_off=leaveresearch())==0)
				{
					break;
				}
				idproduct=-1;
			}
			
		}
		else if( input == 2)
		{
			do
			{
				printf("\nInput the article's name: ");
				fgets(buffer, MAX_LIMIT, stdin);
				buffer[strcspn(buffer, "\n")] = '\0';
				if(checkBufferFormat(buffer)!=1)
				{
					printf("Invalid format");
				}
			}while(checkBufferFormat(buffer)!=1||strlen(buffer)==0);
			
			for(int i = 0 ; i<nb_articles;i++)
			{
				if(strcmp(buffer,products[i].name)==0)
				{
					printf("\n%s quantity:%d",products[i].name,products[i].quantity);
					printf("\nWould you like to leave or search again 1) yes 2) no");
					scanf("%d",&toleave);
					found=1;
					if(toleave==2)
					{
						on_off=0;
					}
				}
			}
		}
			input=-1,found=0;
	}
}

int leaveresearch()
{
	int toleave;
	printf("\nWould you like to leave or search again 1) yes 2) no");
	scanf("%d",&toleave);
	if(toleave==2)
	{
		return 0;
	}
	return 1;
}
