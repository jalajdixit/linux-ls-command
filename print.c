
/* ls command print function */

#include"myheader.h"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLACK "\e[40m"
#define CYAN "\e[36m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

void printlist(int i)
{
	struct passwd *uid;
	struct group *gid;
	struct stat v;
	char *tcp;
	char lstime[30],prwx[11],filename[200];
	if(i<fno)
	{
		bzero(filename,200);
		strcpy(filename,path[con]);
		strcat(filename,list[i]);
		lstat(filename,&v);
		if(opa)
		total+=v.st_blocks/2;
		else
		if(list[i][0]!='.')
		total+=v.st_blocks/2;
		printlist(i+1);
		if(opi)
		{
			if(opa)
			printf("%8d ",v.st_ino);
			else
			if(list[i][0]!='.')
				printf("%8d ",v.st_ino);
		}

		if(ops)
		{
			if(opa)
			printf("%2d ",v.st_blocks/2);
			else
			if(list[i][0]!='.')
				printf("%2d ",v.st_blocks/2);

		}

		if(opl)
		{
			bzero(lstime,30);

			strcpy(lstime,ctime(&v.st_mtime));
			tcp=&lstime[4];
			lstime[16]='\0';

			if(S_ISREG(v.st_mode))
			prwx[0]='-';
			if(S_ISDIR(v.st_mode))
			prwx[0]='d';
			if(S_ISLNK(v.st_mode))
			prwx[0]='l';
			if(S_ISFIFO(v.st_mode))
			prwx[0]='p';
			if(S_ISCHR(v.st_mode))
			prwx[0]='c';
			if(S_ISBLK(v.st_mode))
			prwx[0]='b';
			if(S_ISSOCK(v.st_mode))
			prwx[0]='s';

			prwx[1]=v.st_mode & S_IRUSR ?'r':'-';
			prwx[2]=v.st_mode & S_IWUSR ?'w':'-';
			prwx[3]=v.st_mode & S_IXUSR ?'x':'-';
			prwx[4]=v.st_mode & S_IRGRP ?'r':'-';
			prwx[5]=v.st_mode & S_IWGRP ?'w':'-';
			prwx[6]=v.st_mode & S_IXGRP ?'x':'-';
			prwx[7]=v.st_mode & S_IROTH ?'r':'-';
			prwx[8]=v.st_mode & S_IWOTH ?'w':'-';
			prwx[9]=v.st_mode & S_IXOTH ?'x':'-';
			prwx[10]='\0';

			uid=getpwuid(v.st_uid);
			gid=getgrgid(v.st_gid);

			if(opa)
			{
				printf("%s ",prwx);
				printf("%2d ",v.st_nlink);
				printf("%s ",uid->pw_name);
				printf("%s ",gid->gr_name);
				printf("%5d ",v.st_size);
				printf("%s ",tcp);
			}
			else
				if(list[i][0]!='.')
				{
					printf("%s ",prwx);
					printf("%2d ",v.st_nlink);
					printf("%s ",uid->pw_name);
					printf("%s ",gid->gr_name);
					printf("%5d ",v.st_size);
					printf("%s ",tcp);
				}	
		}

		if(opa)
		{
			if(prwx[0]=='d')
			printf(BOLD BLUE"%s\n"RESET,list[i]);
			else if(prwx[0]=='l')
			printf(BOLD CYAN"%s\n"RESET,list[i]);
			else if(prwx[0]=='p')
			printf(YELLOW BLACK"%s\n"RESET,list[i]);
			else if(prwx[3]=='x')
			printf(BOLD GREEN"%s\n"RESET,list[i]);
			else
			printf("%s\n",list[i]);
		}
		else
			if(list[i][0]!='.')
			{
				if(prwx[0]=='d')
				printf(BOLD BLUE"%s\n"RESET,list[i]);
				else if(prwx[0]=='l')
				printf(BOLD CYAN"%s\n"RESET,list[i]);
				else if(prwx[0]=='p')
				printf(YELLOW BLACK"%s\n"RESET,list[i]);
				else if(prwx[3]=='x')
				printf(BOLD GREEN"%s\n"RESET,list[i]);
				else
				printf("%s\n",list[i]);
			}
	}
	else
	{
		if(i==fno && (ops || opl))
		printf("total %d\n",total);
		return;
	}
}
