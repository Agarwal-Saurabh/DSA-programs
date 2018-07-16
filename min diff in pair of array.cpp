#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[5],i,j,diff1,diff2,pick;
	cout<<"elements of array\n";
	for(i=0;i<5;i++)
	cin>>a[i];
   
    
        diff1=(a[1]-a[0]);	
         pick=diff1;
     
		for(j=4;j>0;j--)
    	{
    		diff2=(a[j]-a[j-1]);
	       
	    	if(pick>diff2)
	       	{
		     	pick=diff2;
		    }
	    	else
		        continue;
       	}
	cout<<pick;
	getch();
	return 0;
	
}
