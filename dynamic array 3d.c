#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int **p,rows,cols,i,j;
	printf("Enter rows & cols\n");
	scanf("%d %d",&rows,&cols);
	p=calloc(rows,sizeof(int *));
	if(p==NULL)
	{
		printf("insufficient/n");
		getch();
		exit(1);
	}
for(i=0;i<rows;i++)
{
	p[i]=calloc(cols,sizeof(int));
    if(p[i]==NULL)
	{
	printf("insufficient\n");
	getch();
	exit(2) ;
}}
printf("Enter \n");
for(i=0;i<rows;i++)
 {
 for(j=0;j<cols;j++)
 {
 	
 scanf("%d",&
 p[i][j]);
 }
}
getch();
}
