#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int info;
	struct queue *link;
};
void create(struct queue **node)
{
	*node=malloc(sizeof( struct queue));
	 {
    printf("Overflow\n");
    getch();
    exit(1);
    }
}
void insert_queue(struct queue **start)
{
	int item;
	struct queue *front,*rear,*temp;
	create(&temp);
	printf("enter item to be inserted\n");
	scanf("%d",&item);
	temp->info=item;
	if(front==NULL)
	{
		front=rear=temp;
	}
	else
	rear->link=temp;
	rear=temp;
}
void delete_queue(struct queue **start)
{
	struct queue *temp,*front,*rear;
	if(front==NULL)
	{
		printf("underflow\n");
		return;
	}
	temp=front;
	if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->link;
	}
	free(temp);
}
void main()
{
	struct queue *start=NULL;
	int choice;
	do
   {
     printf("Press 1 for delete_queue\n");
     printf("Press 2 for Insert_queue\n");
    printf("Press 11 for exit\n");
    printf("Press your choice\n");
    scanf("%d",&choice);
     switch(choice)
     {
        case 1:
           delete_queue(&start);  
           break;
        case 2:
             insert_queue(&start);
           break;
        case 3:
             exit(1);
           break;
        default:
            printf("Please enter valid choice\n");
     }
     getch();
     system("cls");
   }while(choice!=3);
   getch();
}
