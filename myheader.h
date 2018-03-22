
/* Header files */
#ifndef _LS_HEADER
#define _LS_HEADER

#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<utime.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<dirent.h>
#include<strings.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/resource.h>

void makelist(void);
void sortlist(void);
void noplist(void);
void revlist(void);
void printlist(int);

char **list;
char opa,opi,opl,opr,ops;
int fno,len,big;

char *path[10];
int dno,con,total;

#endif
