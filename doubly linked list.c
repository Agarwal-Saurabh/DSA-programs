#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct doubly
{
  int info;
  struct doubly *prev;
  struct doubly * next;     
};
void create(struct doubly **);
void insert_sorted(struct doubly **);
void insert_start(struct doubly **);
void insert_anypos(struct doubly **);
void insert_end(struct doubly **);
void traverse_forward(struct doubly *);
//void reverse(struct singly **);
//void sort(struct singly *);
//void linear_search(struct singly *);
void Delete_start(struct doubly **);
void Delete_end(struct doubly **);
void Delete_anynode(struct doubly **);

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
     printf("Press 10 for insert_sorted\n");
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
        case 3:
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
        /*case 8:
             sort(start);
           break;
        case 9:
             reverse(&start);
           break;
        */case 10:
             insert_sorted(&start);
           break;
        case 11:
            printf("Exiting from program\n");
            break;
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
void insert_start(struct doubly **start)
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
void insert_end(struct doubly **start)
{
	int item;
	struct doubly *temp,*ptr,*pptr ;
	create(&temp);
	printf("Enter item\n");
	scanf("%d",&item);
	temp->info=item;
	temp->next=NULL;
	ptr=*start;
	pptr=NULL;
	while(ptr!=NULL)
	{   
	    pptr=ptr;
		ptr=ptr->next;
	}	
	if(pptr!=NULL)
	{
		pptr->next=temp;
	}
	else
	*start=temp;
	temp->prev=pptr;
}
void insert_sorted(struct doubly **start)
{
	int item;
	struct doubly *temp,*ptr,*pptr ;
	create(&temp);
	printf("Enter item\n");
	scanf("%d",&item);
	temp->info=item;
	ptr=*start;
	pptr=NULL;
	while(ptr!=NULL&&temp->info>ptr->info)
	{
		pptr=ptr;
		ptr=ptr->next;
	}
	if(pptr==NULL)
	{
		temp->next=*start;
		temp->prev=NULL;
		if(*start!=NULL)
		{
			(*start)->prev=temp;
		}
		*start=temp;
		return;
	}
	temp->prev=pptr;
	temp->next=ptr;
	pptr->next=temp;
	if(ptr!=NULL)
	{
		ptr->prev=temp;
	}
	
}
void insert_anypos(struct doubly **start)
{
		int item,i=1,pos;
	struct doubly *temp,*ptr,*pptr ;
	printf("Enter item\n");
	scanf("%d",&item);
    printf("Enter position\n");
	scanf("%d",&pos);
    pptr=NULL,ptr=*start;
    while(ptr!=NULL&&i<pos)
    {
    	pptr=ptr;
    	ptr=ptr->next;
    	i++;
	}
	if(pos<1||pos>i)
	{
		printf("invalid position\n");
		return;
	}
	create(&temp);
	temp->info=item;
	if(pos==1)
	{
		temp->next=*start;
		temp->prev=NULL;
		if(*start!=NULL)
		{
			(*start)->prev=temp;
		}
		*start=temp;
		return;
	}
	temp->prev=pptr;
	temp->next=ptr;
	
	pptr->next=temp;
	if(ptr!=NULL)
	{
		ptr->prev=temp;
	}
}
void Delete_start(struct doubly **start)
{
	struct doubly *temp,*ptr,*pptr;
	if(*start==NULL)
	{
	printf("underflow\n");
	return;
	}
	temp=*start;
	*start=(*start)->next;
	if(*start!=NULL)
	{
		(*start)->prev=NULL;
	}
	free(temp);
}
void Delete_end(struct doubly **start)
{
	struct doubly *temp,*ptr,*pptr;
	if(*start==NULL)
	{
	printf("underflow\n");
	return;
	}
	ptr=*start;
	pptr=NULL;
	while(ptr->next!=NULL)
	{
		pptr=ptr;
		ptr=ptr->next;
	}
	temp=ptr;
	if(pptr!=NULL)
	{
		pptr->next=NULL;
	}
	else
	*start=NULL;
	free(temp);
}
void Delete_anynode(struct doubly **start)
{
	struct doubly *ptr,*pptr;
	int item;
	if(*start==NULL)
	{
		
		printf("underflow\n");
		return;
	}
	ptr=*start;
	pptr=NULL;
	printf("enter item to delete\n");
	scanf("%d",&item);
	while(ptr!=NULL&&item!=ptr->info)
	{
		pptr=ptr;
		ptr=ptr->next;
		
	}
	if(pptr==NULL)
	{
		*start=(*start)->next;
		if(*start!=NULL)
		{
			(*start)->prev=NULL;
		}
	}
		else
		pptr->next=ptr->next;
		if(ptr->next!=NULL)
		{
			ptr->next->prev=pptr;
	
		}
	
			free(ptr);
}
