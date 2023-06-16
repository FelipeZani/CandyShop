#ifndef CANDY_SHOP
#define CANDY_SHOP

//Custommer Macro
#define SIZE_CUSTOMMERPATH 18

//Store macros
#define NB_ARTICLES_BEGINNING 5
#define NB_CUSTOMMER_BEGINNING 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char * last_name;
	//~ Article last_purchase;  
	
} Custommer;

typedef struct Shop
{
	int nb_articles;
	int nb_custommers;
}Shop;

//article functions
void genArticle( char * name, char size, int reference_id,int quantity, float price);
Article * uploadArticles(Article * products, int nb_articles);

//Custommer functions
void genCustommer( char * name, char * last_name);

//shop functions
Shop * storeSetUp(Shop *store);
void management(Shop * store);
void checkStock(Article * products,int nb_articles);

// Tools functions
void IsAllocated(void *p1);

#endif
