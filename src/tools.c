#include "candyshop.h"

void IsAllocated(void * p1)
{
	if(p1==NULL)
	{
		printf("memory wrongly allocated");
		return;
	}
		
}
char * fixname(char * string, int size, char replace, char replaceby)
{
	for(int i=0; i<size; i++)
	{
		if(string[i]==replace)
			string[i]=replaceby;
	}
	return string;
}
void cleanbuffer()
{
	int c; 
	while(c=getchar()!='\n'&& c != EOF)
	continue;
}

int checkBufferFormat(char * buffer)
{
	int index=0;
	int count=0;
	while(buffer[index]!='\0')
	{
		if(isalpha(buffer[index])!=0 || buffer[index] == ' ')
		{
			count++;
			if(buffer[index] == ' ' && buffer[index+1] == ' ')
				return 0;
		}
		index++;
	}
	if(count==strlen(buffer))
		return 1;
	else
		return 0;
}
