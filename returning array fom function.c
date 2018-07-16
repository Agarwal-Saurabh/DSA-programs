#include<stdio.h>
#include<conio.h>
float *create(int *);
void main()
{
	float *p;
	int size,i;
	p=create(&size);
	printf("values are\n");
	for(i-0;i<size;i++)
	printf("%f",p[i]);
	getch();
}
float *create(int *s)
{
	static float a[5]={1.1,1.2,1.3,1.4,1.5};
	*s=5;
	return a;
}
