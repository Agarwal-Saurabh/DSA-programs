#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct singly
{
	int info;
	struct sigly *link;
};
void create(struct singly **);
void insert_start(struct singly **);
int main()
{
	struct singly *start=NULL;
	insert_start(&start);
	getch();
}
void create(struct singly **node)
{
	*node=malloc(sizeof(struct singly));
	if(*node==NULL)
	{
		printf("overflow\n");
		getch();
		return 0;
		exit(1);
	}
}
void insert_start(struct singly **start1)
{
	int item;
	struct singly *temp;
	create(&temp);
	print("enter the item\n");
	scanf("%d",&item);
	temp->info=item;
	temp->link=*start1;
	*start1=temp;
	printf("node inserted successfully\n");
}
