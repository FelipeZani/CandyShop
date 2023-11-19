#include "candyshop.h"

void genCustommer( char * name, char * last_name)
{
	char buffer[100];
	
	snprintf(buffer,sizeof(buffer)+SIZE_CUSTOMMERPATH, "./custommer/%s_%s.txt",name,last_name);	
	
	char * path = malloc(sizeof(strlen(buffer)));
	strcpy(path,buffer);

	FILE * file=fopen(buffer, "a");
	fprintf(file, "%s %s \n ", name, last_name);
	fclose(file);
	
	file = fopen("./custommer/stand.txt","a");
	fprintf(file,"%s_%s\n", name,last_name);
	fclose(file);
}

int checkCustommerInDB(char * nameInput)
{
	FILE * fstand = fopen("./custommer/stand.txt","r");
	char custommer[50];
	while(fscanf(fstand,"%s",custommer) != EOF)
	{
		if(strcmp(custommer,nameInput)==0)
		{
			return 1;
		}
		strcpy(custommer,"");
	}
	return 0;
}

