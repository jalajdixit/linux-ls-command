
/* ls command */

#include"myheader.h"
void main(int argc,char *argv[])
{
	int i,j;
	char option[10]="";

	if(argc==1)		//normal printing for ls
	goto here;

	for(i=1,dno=0;i<argc;i++)
	{
		if(argv[i][0]=='-')	// Options
		strcat(option,&argv[i][1]);
		else			// Directory
		path[dno++]=argv[i];
	}

	for(i=0;option[i];i++)
	{
		switch(option[i])
		{
			case 'a': opa=1; break;
			case 'i': opi=1; break;
			case 's': ops=1; break;
			case 'l': opl=1; break;
			case 'r': opr=1; break;
			default: printf("Invalid Option: -%c\n",option[i]); return;
		}
	}
here:
	if(!dno)
	{
		dno=1;
		path[0]="./";
	}

	for(i=0;i<dno;i++)
	{
		makelist();
		sortlist();
		revlist();
		if(opr)
		revlist();
		total=0;
		if(dno>1)
		printf("%s:\n",path[i]);		
		printlist(0);
		con++;
		if(i+1!=dno)
		printf("\n");
	}
}
