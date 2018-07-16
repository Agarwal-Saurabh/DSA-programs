#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
int precedence(char op);
int isoperator(char op);
void main()
{
   char infix[100],postfix[100],stack[100];
   int i,j=0,top=-1;
printf("Enter the infix expression\n");
  gets(infix);
  for(i=0;infix[i]!='\0';i++)
  {
     if(infix[i]=='(')
       stack[++top]='(';
     else if(isalpha(infix[i]))
       postfix[j++]=infix[i];
     else if(infix[i]==')')
     {
        while(stack[top]!='(')
        {
          postfix[j++]=stack[top--];                     
        }  
        top--; // to remove the left paranthesis
     }  
     else if(isoperator(infix[i]))
     {
while(precedence(stack[top])>=precedence(infix[i]))
{
   postfix[j++]=stack[top--];                                                                        
}   
stack[++top]=infix[i];
     }
     else
     {
       printf("Invalid symbol");
       getch();
       exit(1);  
     }                                
  }
  while(top>=0)
  {
    postfix[j++]=stack[top--];           
  }
 
  postfix[j]='\0';
   printf("The converted postfix expression\n");
  printf("%s",postfix);
  getch();    
}
int precedence(char op)
{
  if(op=='^')
  return 3;
  else if(op=='*'||op=='/'||op=='%')
  return 2;
  else if(op=='+'||op=='-')
  return 1;
  else
  return 0;
}
int isoperator(char op)
{
  if(op=='^'||op=='+'||op=='-'||op=='/'||op=='*'
  ||op=='%')
  return 1;
  else
  return 0;  
}
