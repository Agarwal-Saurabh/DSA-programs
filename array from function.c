#include<conio.h>
#include<stdio.h>
void create(int **,int *);
void main()
{
float *p;
int size,i;
create(&p,size);
printf("values are\n");
for(i=0;i<size;i++)
printf("%f",p[i]);
getch();
}
void create(int **a,int *s)
{
	static float m[5]={1.1,1.2,1.3,1.4,1.5};
	*s=5;
	**a=m;
}
