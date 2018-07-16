#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[5][5],alt[5][3],nz=0,i,j,row;
	cout<<"enter sparse\n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	
	alt[0][1]=5;
	alt[0][2]=5;
	row=1;
		for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]!=0)
			{
				alt[row][1]=i;
				alt[row][2]=j;
				alt[row][0]=a[i][j];
				row++;
				nz++;
			}
		}
	}
	alt[0][0]=nz;
		for(i=0;i<nz+1;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<alt[i][j];
			}
		}
		getch();
}
