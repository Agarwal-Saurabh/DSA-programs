#include<stdio.h>
#include<conio.h>
int facto(int n)
{
	static int i=1,f=1;
	if(i<=n)
	{
		f=f*i;
		i++;
		facto(n);
	}
	return f;
}
int main()
{
	int n;
	printf("Enter no\n");
	scanf("%d",&n);
printf("facto=%d",facto(n));	
	getch();
}

