#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct doubly
{
  int info;
  struct doubly *prev;
  struct doubly * next;     
};
//void create(struct singly **);
void insert_start(struct doubly **);
//void insert_anypos(struct singly **);
//void insert_end(struct singly **);
void traverse_forward(struct doubly *);
//void reverse(struct singly **);
//void sort(struct singly *);
//void linear_search(struct singly *);
//void Delete_start(struct singly **);
//void Delete_end(struct singly **);
//void Delete_anynode(struct singly **);

int main()
{
  struct doubly *start=NULL;
  int choice;
   do
   {
     printf("Press 1 for Traversing forward\n");
     printf("Press 2 for Insert_start\n");
     printf("Press 3 for Insert_end\n");
     printf("Press 4 for Insert_anypos\n");
     printf("Press 5 for Delete_start\n");
     printf("Press 6 for Delete_end\n");
     printf("Press 7 for Delete_anynode\n");
     printf("Press 8 for sort\n");
     printf("Press 9 for Reverse\n");
     printf("Press 10 for Linear search\n");
     printf("Press 11 for exit\n");
     printf("Press your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:
           traverse_forward(start);  
           break;
        case 2:
             insert_start(&start);
           break;
        /*case 3:
             insert_end(&start);
           break;
        case 4:
             insert_anypos(&start);
           break;
        case 5:
        	Delete_start(&start);
           break;
        case 6:
        	Delete_end(&start);
           break;
        case 7:
        	Delete_anynode(&start);
           break;
        case 8:
             sort(start);
           break;
        case 9:
             reverse(&start);
           break;
        case 10:
             linear_search(start);
           break;
        case 11:
            printf("Exiting from program\n");
            break;*/
        default:
            printf("Please enter valid choice\n");
     }
     getch();
     system("cls");
   }while(choice!=12);
   getch();  
} 
void create(struct doubly **node)
{
  *node=malloc(sizeof(struct doubly));
  if(*node==NULL)  
  {
    printf("Overflow\n");
    getch();
    exit(1);
  }
}
void traverse_forward(struct doubly *start)
{
	struct doubly *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("empty\n");
	}
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
}
void traverse_backward(struct doubly *start)
{
	struct doubly *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("empty\n");
	}
	while(ptr!=NULL)
	{
		ptr=ptr->next;
	}
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->prev;
	}
}
void insertion_start(struct doubly **start)
{
	int item;
	struct doubly *temp;
	create(&temp);
	printf("Enter item\n");
	scanf("%d",&item);
	temp->info=item;
	temp->next=*start;
	temp->prev=NULL;
	if(*start!=NULL)
	{
		(*start)->prev=temp;
	}
	*start=temp;
}
