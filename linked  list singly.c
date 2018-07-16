#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct singly
{
  int info;
  struct singly * link;     
};
void create(struct singly **);
void insert_start(struct singly **);
void insert_anypos(struct singly **);
void insert_end(struct singly **);
void traverse(struct singly *);
void reverse(struct singly **);
void sort(struct singly *);
void linear_search(struct singly *);
void Delete_start(struct singly **);
void Delete_end(struct singly **);
void Delete_anynode(struct singly **);
void main()
{
  struct singly *start=NULL;
  int choice;
   do
   {
     printf("Press 1 for Traversing\n");
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
           traverse(start);  
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
            break;
        default:
            printf("Please enter valid choice\n");
     }
     getch();
     system("cls");
   }while(choice!=12);
   getch();  
} 
void linear_search(struct singly *start)
{
  int item;
  struct singly *ptr;
  if(start==NULL)
  {
    printf("Empty list\n");           
    return;
  }   
  printf("Enter the item to be found\n");
  scanf("%d",&item);
  ptr=start;
  while(ptr!=NULL)
  {
    if(item==ptr->info)
    {
      printf("Node found\n");
      return;
    }        
    ptr=ptr->link;      
  }
      printf("Node not found\n");
}
void sort(struct singly *start)
{
  struct singly *ptr1,*ptr2;
  int t;
  if(start==NULL)
  {
    printf("Empty list\n");           
    return;
  }   
  ptr1=start;
  while(ptr1->link!=NULL)
  {
     ptr2=ptr1->link;
     while(ptr2!=NULL)
     {
        if(ptr1->info>ptr2->info) 
        {
      t=ptr1->info,ptr1->info=ptr2->info;
      ptr2->info=t;                            
        }          
        ptr2=ptr2->link;   
     }                    
        ptr1=ptr1->link;  
  }    
  printf("Link list is sorted now\n");
}
void traverse(struct singly *ptr)
{
  if(ptr==NULL)
  {
    printf("Empty list\n");           
    return;
  }   
  printf("Travesing begins\n");
  while(ptr!=NULL)
  {
     printf("%d  ",ptr->info);             
     ptr=ptr->link;
  }
  printf("\nTraversing finished\n");
}
void reverse(struct singly **start)
{
  struct singly *start1=NULL,*p2;
  if(*start==NULL)
  {
    printf("Empty list\n");           
    return;
  }   
  while(*start!=NULL)
  {
     p2=*start;
     *start=(*start)->link;
     p2->link=start1;
     start1=p2;                
  }
  *start=start1;
  printf("Link list is reversed\n");
}
void create(struct singly **node)
{
  *node=malloc(sizeof(struct singly));
  if(*node==NULL)  
  {
    printf("Overflow\n");
    getch();
    exit(1);
  }
}
void insert_start(struct singly **start1)
{
  // *start1==start     
   int item;
   struct singly *temp;
   create(&temp);
   printf("Enter the item\n");
   scanf("%d",&item);
   temp->info=item;
   temp->link=*start1;
   *start1=temp;
   printf("Node inserted successfully\n");
}
void insert_end(struct singly **start1)
{
   int item;
   struct singly *temp,*ptr,*pptr=NULL;
   create(&temp);
   temp->link=NULL;
   printf("Enter the item\n");
   scanf("%d",&item);
   ptr=*start1;
   temp->info=item;
   while(ptr!=NULL)
   {
     pptr=ptr;
     ptr=ptr->link;
   }
   if(pptr==NULL)
   *start1=temp;
   else
   pptr->link=temp;
}
void insert_anypos(struct singly **start1)
{
 int pos,i=1,item;
 struct singly *temp,*ptr,*pptr=NULL;
 ptr=*start1;
 printf("enter the position\n");
 scanf("%d",&pos);
 while(i<pos&&ptr!=NULL)
 {
    pptr=ptr;
    ptr=ptr->link;
    i++;                    
 }
 if(pos>i)
 {
   printf("Invalid position\n");
   return;       
 }
  create(&temp);
  printf("Enter the item\n");
  scanf("%d",&item);
  temp->info=item;
  if(pptr==NULL)
  {
  temp->link=*start1;
  *start1=temp;
  } 
  else
  {
    pptr->link=temp;
    temp->link=ptr;   
  }
}

void Delete_start(struct singly **start1)
{
	struct singly *temp;
	if(	*start1==NULL)
	{
		printf("underflow\n");
	}
	temp=*start1;
	*start1=(*start1)->link;
    free(temp);
    printf("deletion successfully done\n");
}
void Delete_end(struct singly **start1)
{
	struct singly *temp,*ptr,*pptr;
	if(*start1==NULL)
	{
		printf("underflow\n");
		return;
	}
	ptr=*start1;
	pptr=NULL;
	while(ptr->link!=NULL)
	{
		pptr=ptr;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		*start1=NULL;
	}
	else
	{
		pptr->link=NULL;
	}
	free(ptr);
    printf("deletion successfully done\n");
}
void Delete_anynode(struct singly ** start1)
{
	struct singly *temp,*ptr,*pptr;
	int item;
printf("Enter the item\n");
  scanf("%d",&item);
  	
	if(*start1==NULL)
	{
		printf("underflow\n");
		return;
	}
	ptr=*start1;
	pptr=NULL;
	while(ptr!=NULL)
	{
		if(item=ptr->info);
		{
			goto s;
		}
		pptr=ptr;
		ptr=ptr->link;
	}
	s:
	if(ptr=NULL)
	{
		printf("node not found\n");
		return;
	}
	else if(pptr==NULL)
	{
		*start1=(*start1)->link;
	}
	else
	pptr->link=ptr->link;
	free(ptr);
}
