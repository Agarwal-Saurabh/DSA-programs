#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void create(int **,int);
void main()
{
	int*p;
	int size,i;
	printf("enter the size\n");
	scanf("%d",&size);
	create(&p,size);
	printf("enter array\n");
	for(i=0;i<size;i++)
	scanf("%d",&p[i]);
	free(p);
	getch();
}
void create(int**a,int s)
{
*a=calloc(s,sizeof(int));
if(*a==NULL)
{
	printf("insufficient\n");
	getch();
	exit(0);
}
}
