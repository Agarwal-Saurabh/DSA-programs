#include<stdio.h>
#include<conio.h>
int sum(int n)
{
	if(n==0)
	return 0;
	else
	return n+sum(n-1);
}
int main()
{ int n; 
	scanf("%d",&n);
//	sum(n);
	printf("sum=%d",sum(n));
	getch();
	return 0;
}
