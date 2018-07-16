#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
#define maxp 3
struct prior
{
	int pq[maxp][size],front[maxp],rear[maxp];
	int p;
};
void insert(struct prior *s)
{
	int item;
		printf("Enter priority in which you want to enter element\n");
    scanf("%d",&s->p);
	if(s->p<0||s->p>maxp-1)
	{
		printf("such a priority doesnt exist\n ");
		exit(1);
		getch();
	}
	else if(s->front[s->p]==0&& s->rear[s->p]==size-1||s->front[s->p]==s->rear[s->p]+1)
	{
	printf("overflow\n ");
		exit(2);
		getch();
	}	
	else if(s->front[s->p]=-1)
	{

	s->front[s->p]=s->rear[s->p]=0;
    }
	else if(s->rear[s->p]=size-1)
	{
	
	s->rear[s->p]=0;
	}
	else
	{
		s->rear[s->p]++;
	}
	printf("enter item\n");
	scanf("%d",&item);
	s->pq[s->p][s->rear[s->p]]=item;
    
}


void delete1(struct prior *s)
{

s->p=0;
	while(s->p<maxp&&s->front[s->p]==-1)
	{
		s->p=s->p+1;
	}
	if(s->p>=maxp)
	{
		printf("undrflow\n");
	exit(3);
	getch();
	}
	else if(s->front[s->p]==s->rear[s->p])
	{
		s->front[s->p]=s->rear[s->p]=-1;
		}
		else if(s->front[s->p]==size-1)
	{
			s->front[s->p]=0;
		}
		else 
		{
		s->front[s->p]++;
		}
	
}




void main()
{
  int choice;
  struct prior l;
  
   int i;
   for(i=0;i<maxp;i++)
   {
        l.front[i]=-1;
		l.rear[i]=-1;
	}
   
     
do
{
printf("press 1 to insert\npress 2 to delete\npress 3 to exit\n");
scanf("%d",&choice);

	switch(choice)
{
  
case 1: insert(&l);
  break;
 case 2: delete1(&l);
  break;
case 3:exit(5);
  default:
  printf("invalid\n");
}
}while(choice!=3);
  getch();
}
