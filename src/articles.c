#include "candyshop.h"

void genArticle( char * name, int reference_id, float price, char size)
{

	FILE * file= fopen("./articles/articles.txt", "a");
	if(file == NULL)
	{
		printf("ERROR opening the file");
		exit(-1);
	}
	fprintf(file, "%s %d %2.f %c \n", name, reference_id, price,size);
	fclose(file);
}
