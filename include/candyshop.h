#ifndef CANDY_SHOP
#define CANDY_SHOP

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
	char * nom;
	char * prenom;
	//~ Article orderStory; Verify here 
	
} Custommer;



//article functions
void genArticle( char * name, int reference_id, float price, char size);


#endif
