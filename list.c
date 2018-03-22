
/* ls command */

#include"myheader.h"
void main(int argc,char *argv[])
{
	int i;
	char *path[10],option[10]="",*cp;
	if(argc==1)
	{
		path[0]=".";
	}
	else
	{
		for(i=1;i<argc;i++)
		{
			if(argv[i][0]=='-')
			{// Options
				cp=&argv[i][1];
				strcat(option,cp);

				switch(argv[i][1])
				{
					case 'a': opa=1; break;
					case 'i': opi=1; break;
					case 'l': opl=1; break;
					case 'r': opr=1; break;
					case 's': ops=1; break;
					case 'S': opS=1; break;
					default: printf("Invalid Option: -%c\n",argv[i][1]); return;
				}
			}
			else
			{
				path=argv[i];
				pop=1;
			}
		}
		if(!path)
		path=".";
	}

	makelist(path);
	sortlist();

	if(nop)
	{
		noplist();
		return;
	}
	else if(pop && argc==2)
	{
		noplist();
		return;
	}

	if(opr)
	revlist();
	
	printlist();
}
