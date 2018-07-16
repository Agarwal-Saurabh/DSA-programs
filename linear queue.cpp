#include<stdio.h>
#include<conio.h>
#define size 5
#include<stdlib.h>
void insert_lq(int &rear,int &front,int *lq)
{
	int item;
	if(rear==(size-1))
	{
		printf("overflow\n");
		exit(1);
	}
	else if(front==-1)
	{
		//printf("-1\n");
		front=rear=0;
	}
	else 
	{
	rear++;
	}
	printf("enter item\n");
	scanf("%d",&item);
	lq[rear]=item;
}
void delete_lq(int &front,int &rear,int *lq)
{
	if(front==-1)
	printf("underflow\n");
	else if(front==rear)
	front=rear=-1;
	else
	{
printf("h\n");
	front++;
}}
int main()
{
	int rear=-1,x,front=-1,item,lq[size];
do{
	printf("enter choice\n");
	scanf("%d",&x);

	switch(x)
	{
		case 1:insert_lq(front,rear,lq);
		break;
		case 2:delete_lq(front,rear,lq);
		break;
		case 3: exit(2);
		default:
			printf("invalid\n");
	}}while(1);
	getch();
return 0;
}
