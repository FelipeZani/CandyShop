#include "candyshop.h"

void genCustommer( char * name, char * last_name)
{
	char buffer[100];
	snprintf(buffer,sizeof(buffer)+SIZE_CUSTOMMERPATH, "./custommer/%s_%s.txt",name,last_name);	
	FILE * file=fopen(buffer, "a");
	fprintf(file, "%s %s \n ", name, last_name);
	fclose(file);
}
