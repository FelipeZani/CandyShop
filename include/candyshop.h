#ifndef CANDY_SHOP
#define CANDY_SHOP

//Custommer Macro
#define SIZE_CUSTOMMERPATH 18

//Store macros
#define NB_ARTICLES_BEGINNING 5
#define NB_CUSTOMMER_BEGINNING 3
#include <stdio.h>
#include <stdlib.h>


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
	int * nb_articles;
	int * nb_custommers;
}Shop;

//article functions
void genArticle( char * name, int reference_id,int quantity, float price, char size);
Article * uploadArticles(FILE farticles, Article * products, int nb_articles);

//Custommer functions
void genCustommer( char * name, char * last_name);

//shop functions
void storeSetUp(Shop store);
void management(int nb_artc);


// Tools functions
void IsAllocated(void *p1);

#endif
