#ifndef CANDY_SHOP
#define CANDY_SHOP

//Custommer Macro
#define SIZE_CUSTOMMERPATH 18

//Store macros
#define NB_ARTICLES_BEGINNING 5
#define NB_CUSTOMMER_BEGINNING 3
#define MAX_LIMIT 100
#define MAX_STOCK 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Article
{
	int reference_ID; // product can be found by it or name 
	int quantity;
	float price; 
	char size; //  only 3 sizes available 
	char * name;
}Article;

typedef struct Custommer
{
	char * name;
	char * lastname;
	Article * last_purchase;  
	
} Custommer;

typedef struct Shop
{
	Article * products;
	int nb_articles;
	int nb_custommers;
	int stockmax;
}Shop;

//article functions
void genArticle( char * name, char size, int reference_id,int quantity, float price);
Article * uploadArticles(Article * products, int nb_articles);
void saveArticles(Article * products, int nb_articles);

//Custommer functions
void genCustommer( char * name, char * last_name);
int checkCustommerInDB(char * nameInput);

//shop functions
Shop * storeSetUp(Shop *store);

//management functions
void management(Shop * store);
void checkStock(Article * products,int nb_articles);
int leaveresearch();
int searchArticle(int nb_articles, Article * products);


//purchase functions
void purchase(Shop * store);
void signedIn(Shop * store);
void purchaseItem(Custommer * custo,Shop * store, int index,int amountPurchased);
void signup();


//Add articles function
void addArticle(Article * products,int nb_articles, int maxItems);
int isInTheStore(char * buffer, Article * product,int nb_articles );

// Tools functions
void IsAllocated(void *p1);
char * fixname(char * string, int size, char replace, char replaceby);
void cleanbuffer();
int checkBufferFormat(char * buffer);

#endif
