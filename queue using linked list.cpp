#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int info;
	queue *front,*rear,*link;
}
void create(queue **node)
{
	*node=malloc(sizeof(queue))
	 {
    printf("Overflow\n");
    getch();
    exit(1);
    }
}
void insert_queue(queue **start)
{
	int temp;
	queue *temp;
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
void delete_queue(queue **start)
{
	queue *temp;
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
		fromt=front->link;
	}
	free(temp);
}
void main()
{
	struct queue start==NULL;
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
