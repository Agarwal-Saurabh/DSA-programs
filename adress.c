#include<stdio.h>
#include<conio.h>
int main()
{
	int a[3][4];

printf("%u\n",a);
printf("%u\n",a+1);
printf("%u\n",a[0]);
printf("%u\n",a[0]+1);
printf("%u\n",a[0][0]);
printf("%u\n",a[0][0]+1);
printf("%u\n",&a);
printf("%u\n",&a[0]);
printf("%u\n",&a[0][0]);
printf("%u\n",&a[0]+1);
//printf("%u\n",&(a+1));
printf("%u\n",(a+1));
printf("%u\n",&a+1);
}
