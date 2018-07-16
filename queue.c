#include<conio.h>
#include<stdio.h>
#define n 5
#include<stdlib.h>
struct queue
{
	int front,rear;
	int que[n];
};
void insert_queue(struct queue *s1)
{
	int item;
	if(s1->front==0&&s1->rear==n-1)
	{
		printf("overflow\n");
		return;
	}
	if(s1->front==-1)
	{
		s1->front=s1->rear=0;
	}
	else
	{
	s1->rear=s1->rear+1;
    }
    printf("enter the item\n");
    scanf("%d",&item);
    s1->que[s1->rear]=item;
	
}
void delete_queue(struct queue *s1)
{
	int item;
	if(s1->front==-1)
	{
		printf("underflow\n");
		return;
	}
	item=s1->que[s1->front];
	if(s1->front==s1->rear)
	{
		s1->rear=s1->front=-1;
	}
	else if(s1->front==n-1)
	{
		s1->front=0;
	}
	else
	{
		s1->front=s1->front+1;
	}
	
}
void traversing(struct queue s1)
{
	if(s1.front==-1)
	{
		printf("empty\n");
		return;
	}
	while(s1.front!=s1.rear+1)
	{
		printf("%d \n",s1.que[s1.front]);
		s1.front++;
	}
}
void main()
{
	struct queue s1;
	s1.front=s1.rear=-1;
	int choice;
	do
	{
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Traversing\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_queue(&s1);
				break;
			case 2:
				delete_queue(&s1);
				break;
			case 3:
				traversing(s1);
				break;
			case 4:
				printf("Exiting from program\n");
				getch();
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}while(choice!=4);
getch();
}
