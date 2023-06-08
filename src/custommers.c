#include "candyshop.h"

void genCustommer( char * name, char * last_name /*,Article last_purchase*/)
{

	char buffer[100];
	snprintf(buffer,sizeof(buffer)+SIZE_CUSTOMMERPATH, "./custommer/%s_%s.txt",name,last_name);	
	FILE * file=fopen(buffer, "a");
	fclose(file);
}
