#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],i,b[5],j=0;
	
	cout<<"enter elements\n";
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	} 
	 
	 for(i=0;i<4;i++)
	 {
	 	if(a[i]!=a[i+1])
	 	{
		 
	 	b[j]=a[i];
	 	j++;
	    }
	 }
	 if (a[4]!=a[5])
	 b[j]=a[5];
	 j++;
	 for(i=0;i<j+1;i++)
	 cout<<b[i];
	getch();
}
