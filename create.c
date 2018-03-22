
/* ls command create list */

#include"myheader.h"

void makelist(void)
{
	struct dirent *dire;
	DIR *dip;
	static int co;
	int i;
	dip=opendir(path[co++]);	//Open Directory Path
	if(!dip)
	{
		perror("opendir");
		return;
	}

	fno=big=len=0;
	while(dire=readdir(dip))	//Count No. of Files
	{				//Longest File Name
		fno++;
		len=strlen(dire->d_name);
		if(len>big)
			big=len;
	}
	rewinddir(dip);

	list=malloc(sizeof(char*)*fno);
	for(i=0;i<fno;i++)		//Copy Whole List in a 2D Array
	{
		list[i]=malloc(sizeof(char)*big+1);
		dire=readdir(dip);
		strcpy(list[i],dire->d_name);
	}
	closedir(dip);
}
