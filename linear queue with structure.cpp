#include<stdio.h>
#include<conio.h>
#define size 5
#include<stdlib.h>

struct linear
{
int rear;
int front;
int lq[size];	
};
void insert_lq(struct linear *s)
{
	int item;
	if(s->rear==(size-1))
	{
		printf("overflow\n");
		exit(1);
	}
	else if(s->front==-1)
	{
		
		s->front=s->rear=0;
	}
	else 
     s->rear++;

	printf("enter item\n");
	scanf("%d",&item);
	s->lq[s->rear]=item;
}
void delete_lq(struct linear *s)
{
	if(s->front==-1)
	printf("underflow\n");
	else if(s->front==s->rear)
	s->front=s->rear=-1;
	else
	{
	s->front++;
}}
int main()
{
	int x;
	struct linear s;
	s.rear=s.front=-1;
	
do{
	printf("enter choice\n");
	scanf("%d",&x);

	switch(x)
	{
		case 1:insert_lq(&s);
		break;
		case 2:delete_lq(&s);
		break;
		case 3: exit(2);
		default:
			printf("invalid\n");
	}}while(1);
	getch();
return 0;
}
