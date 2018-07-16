#include<stdio.h>
#include<conio.h>
int st[5],top=-1;
 int item;
 int main()
 {
 start:
    if(top==4)
    {
      printf("Overflow\n");
      return;            
    } 
    printf("Enter the item\n");
    scanf("%d",&item);
    top++;
    st[top]=item;
    printf("Item inserted in stack\n");
    goto start;
    getch();
}
