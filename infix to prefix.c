#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int precedence(char op);
int isoperator(char op);
void main()
{
   char infix[100],prefix[100],stack[100];
   int i,j=0,top=-1;
printf("Enter the infix expression in paranthesis\n");
  gets(infix);
  for(i=strlen(infix)-1;i>=0;i--)
  {
     if(infix[i]==')')
       stack[++top]=')';
     else if(isalpha(infix[i]))
       prefix[j++]=infix[i];
     else if(infix[i]=='(')
     {
        while(stack[top]!=')')
        {
          prefix[j++]=stack[top--];                     
        }  
        top--; // to remove the right paranthesis
     }  
     else if(isoperator(infix[i]))
     {
while(precedence(stack[top])>precedence(infix[i]))
{
   prefix[j++]=stack[top--];                                                                        
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
  prefix[j]='\0';
  strrev(prefix);// to reverse the expression
  printf("The converted prefix expression\n");
  printf("%s",prefix);
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
