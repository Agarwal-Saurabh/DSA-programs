#include<stdio.h>
#include<conio.h>
int n=0; // global variable(no. of elements)
void selection_sort(int *);
void bubble_sort(int *);
void insertion_sort(int *);
void shell_sort(int *);
void linear_search(int *);
void binary_search(int *);
void deletion(int *);
void insert_unsorted(int *,int);
void insert_sorted(int *,int);
void traverse(int *);
void merging();
void main()
{
   int a[10],choice;
   do
   {
     printf("Press 1 for traversing\n");
     printf("Press 2 for Insert_sorted array\n");
     printf("Press 3 for Insert_unsorted array\n");
     printf("Press 4 for Delete an element\n");
     printf("Press 5 for Linear search\n");
     printf("Press 6 for Binary search\n");
     printf("Press 7 for Selection sort\n");
     printf("Press 8 for Bubble sort\n");
     printf("Press 9 for Insertion sort\n");
     printf("Press 10 for Shell sort\n");
     printf("Press 11 for Merging\n");
     printf("Press 12 for exit\n");
     printf("Press your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:
           traverse(a);
           break;
        case 2:
           insert_sorted(a,10);
           break;
        case 3:
           insert_unsorted(a,10);
           break;
        case 4:
           deletion(a);
           break;
        case 5:
           linear_search(a);
           break;
        case 6:
           binary_search(a);
           break;
        case 7:
           selection_sort(a);
           break;
        case 8:
           bubble_sort(a);
           break;
        case 9:
           insertion_sort(a);
           break;
        case 10:
           shell_sort(a);
           break;
        case 11:
            merging();
            break;
        case 12:
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
void selection_sort(int *a)
{
  int i,j,t;
    printf("Selection sort begins here\n");
    for(i=0;i<n-1;i++)
    {
       for(j=i+1;j<n;j++)
       {
          if(a[i]>a[j]) 
          {
           t=a[i],a[i]=a[j],a[j]=t;             
          }              
       }               
    }   
printf("\nArray is now sorted in ascending order\n");
}
void bubble_sort(int *a)
{
  int i,j,t,found=0;
    printf("Bubble sort begins here\n");
    for(i=1;i<n&&found==0;i++)
    {
       found=1;
       for(j=0;j<n-i;j++)
       {
          if(a[j]<a[j+1]) 
          {
           t=a[j],a[j]=a[j+1],a[j+1]=t,found=0;      
		   // traverse(a);  to see passes     
          }              
       }               
    }   
printf("\nArray is now sorted in descending order\n");   
}
void insertion_sort(int *a)
{
  int i,j,pick;
  printf("Insertion sort begins here\n");
  for(i=1;i<n;i++)
  {
     pick=a[i];
     for(j=i-1;j>=0&&pick>a[j];j--)
     {
       a[j+1]=a[j];   
	                         
     }             
     a[j+1]=pick;
    //  traverse(a);   to see passes  
  }  
printf("\nArray is now sorted in descending order\n");        
}
void shell_sort(int *a)
{
  int i,j,pick,gap=n/2;
  printf("Shell sort begins here\n");
  while(gap>=1)
  {
     for(i=gap+1;i<n;i++)
     {
        pick=a[i];
        for(j=i-gap;j>=0&&pick<a[j];j=j-gap)
        {
         a[j+gap]=a[j];  
		  traverse(a);                            
        }             
        a[j+gap]=pick;
     }         
     gap=gap/2;   
  }   
printf("\nArray is now sorted in Ascending order\n");          
}
void linear_search(int *a)
{
  int i,item;
  if(n==0)
  {
     printf("Empty array\n");
     return;     
  }   
  printf("Enter the item to be searched\n");
  scanf("%d",&item);
  for(i=0;i<n;i++)
  {
    if(item==a[i])
    {
      printf("Element found at index=%d\n",i);
      getch();
      return;            
    }              
  }
  printf("Element not found\n");
}
void binary_search(int *a)
{
  int i,item,LB=0,UB=n-1,MID;
  if(n==0)
  {
     printf("Empty array\n");
     return;     
  }   
  printf("Enter the item to be searched\n");
  scanf("%d",&item);
  while(LB<=UB)
  {
     MID=(LB+UB)/2;
     if(item==a[MID])
     {
      printf("Element found at index=%d\n",MID);
      getch();
      return;            
     }          
     else if(item>a[MID])
     LB=MID+1;
     else
     UB=MID-1;
  }
  printf("Element not found\n");
}
void deletion(int *a)
{
   int i,pos;
   if(n==0)
   {
     printf("Empty array cant delete\n");      
     return;
   }  
printf("Enter the position of element to delete\n");
   scanf("%d",&pos);
   if(pos<0||pos>=n)
   {
      printf("Invalid position\n");
      getch();
      return;              
   }
   for(i=pos;i<n;i++)
   {
     a[i]=a[i+1];                
   }
   n--;
   printf("Element deleted successfully\n");
}
void insert_unsorted(int *a,int size)
{
   int i,pos,item;
   if(n==size)
   {
     printf("Overflow\n"); 
     getch();
     return;        
   }     
printf("Enter the position of element to insert\n");
   scanf("%d",&pos);
   if(pos<0||pos>n)
   {
      printf("Invalid position\n");
      getch();
      return;                              
   }
printf("Enter the item\n");
scanf("%d",&item);
for(i=n-1;i>=pos;i--)
{
  a[i+1]=a[i];                   
}   
  a[pos]=item;
  n++;
  printf("Item inserted successfully\n");  
}
void insert_sorted(int *a,int size)
{
   int i,pos,item;
   if(n==size)
   {
     printf("Overflow\n"); 
     getch();
     return;        
   }     
printf("Enter the item to be inserted\n");
scanf("%d",&item);
for(pos=0;pos<n&&item>a[pos];pos++)
{}//increasing order
for(i=n-1;i>=pos;i--)
{
  a[i+1]=a[i];                   
}   
  a[pos]=item;
  n++;
  printf("Item inserted successfully\n");  
}
void merging()
{
  int a[6],b[8],c[14];
  int i,j,k;
 printf("Enter the array1 in sorted order\n");
 for(i=0;i<6;i++)
 scanf("%d",&a[i]);
 printf("Enter the array2 in sorted order\n");
 for(i=0;i<8;i++)
 scanf("%d",&b[i]);
 i=0,j=0,k=0;
 while(i<6&&j<8)
 {
   if(a[i]<b[j])
   c[k++]=a[i++];
   else
   c[k++]=b[j++];             
 }
 while(i<6)// to copy remaining array1
 {
   c[k++]=a[i++];
 }
 while(j<8)// to copy remaining array2
 {
   c[k++]=b[j++];             
 }
 printf("Array after merging\n");
 for(k=0;k<14;k++)
 printf("%d ",c[k]);
 printf("\nMerging finished\n");    
}
void traverse(int *a)
{
  int i;
   printf("Traversing begins here\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);              
   }    
   printf("\nTraversing ends here\n");
}
