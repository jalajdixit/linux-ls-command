
/* ls command */

#include"myheader.h"

void sortlist(void)		  //Sort the 2D Array Alphabetically
{
	char *temp;
	int i,j;
	temp=malloc(sizeof(char)*big+1);
	for(i=0;i<fno-1;i++)		
	for(j=0;j<fno-1-i;j++)
	{
		if(strcasecmp(list[j],list[j+1])>0)
		{
			strcpy(temp,list[j]);
			strcpy(list[j],list[j+1]);
			strcpy(list[j+1],temp);
		}
	}
}

void noplist(void)			//Print the List
{
	int i;
	for(i=0;i<fno;i++)
	if(list[i][0]!='.')
		printf("%s\t",list[i]);
	printf("\n");
}

void revlist(void)			//Reverse the List
{
	int i,j;
	char *temp;
	for(i=0,j=fno-1;i<j;i++,j--)
	{
		strcpy(temp,list[j]);
		strcpy(list[j],list[i]);
		strcpy(list[i],temp);
	}
}
