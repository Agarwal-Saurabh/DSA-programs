#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
main()
{
	int *p,**q,i,size;
	q=&p;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	p=malloc(size*sizeof(int));
	printf("Enter array elements\n"); 
	for(i=0;i<size;i++)
	scanf("%d",&p[i]);
	printf("array elements:\n");
	for(i=0;i<size;i++)
	printf("%d\n",p[i]);
	printf("%u\n",q);
	printf("%u\n",q+1);
	printf("%u\n",q+2);
	printf("%d",sizeof(**q));
	free(p);
	getch();
}
