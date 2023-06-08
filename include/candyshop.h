#ifndef CANDY_SHOP
#define CANDY_SHOP

//Custommer Macro
#define SIZE_CUSTOMMERPATH 18

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



//article functions
void genArticle( char * name, int reference_id, float price, char size);

//Custommer functions
void genCustommer( char * name, char * last_name /*,Article last_purchase*/);

#endif
