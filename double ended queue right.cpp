#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define size 5
struct doubly
{
	int dq[size];
	int left=-1,right=-1;
};
void insert_right(struct doubly *s)
{
	int item;
	if(s->left==0&&s->right==size||s->left==s->right+1)
	{
		printf("overflow\n");
		exit(2);
	}
	else if(s->right==-1)
	{
		s->left=s->right=0;
	}
	else if(s->right==size-1)
	{
		s->right=0;
	}
	else
	{
	s->right++;
    }
    	printf("enter item\n");
	scanf("%d",&item);
    s->dq[s->right]=item;
}
void delete_right(struct doubly *s)
{
	if(s->right==-1)
	{
		printf("underflow\n");
		exit(3);
	}
	else if(s->left==s->right)
	{
		s->left=s->right=-1;
	}
	else if(s->right==0)
	{
		s->right==size-1;
	}
	else
	{
		s->right--;
	}
}
int main()
{
	doubly l;
	int choice;
	
	 do
{
printf("press 1 to insert\npress 2 to delete\npress 3 to exit\n");
scanf("%d",&choice);

	switch(choice)
{
  
case 1: insert_right(&l);
  break;
case 2: delete_right(&l);
  break;
case 3:exit(5);
  default:
  printf("invalid\n");
}
}while(choice!=3);
  getch();
  return 0;
}

