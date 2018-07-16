#include<stdio.h>
#include<conio.h>
int posteval(char*);
int preeval(char*);
void main()
{
  char pre[100],post[100];
  int result;
  printf("Enter the postfix expression with constant\
  values\n");
  gets(post);
  result=posteval(post);
  printf("Result=%d\n",result);
  printf("Enter the prefix expression with constant\
  values\n");
  gets(pre);
  result=preeval(pre);
  printf("Result=%d\n",result);
  
  getch();     
}
int posteval(char* post)
{
  int stack[100],top=-1;
  int i,op1,op2,r;
  for(i=0;post[i]!='\0';i++)
  {
    if(post[i]>='0'&&post[i]<='9') 
    {
      stack[++top]=post[i]-48;                             
    }
    else
    {
      op2=stack[top--];
      op1=stack[top--];
      switch(post[i])
      {
        case '+':
           r=op1+op2;
           break;
        case '-':                  
           r=op1-op2;
           break;
        case '*':                  
           r=op1*op2;
           break;
        case '/':                  
           r=op1/op2;
           break;
        case '%':                  
           r=op1%op2;
           break;
        case '^':                  
           r=(int)pow(op1,op2);
           break;   
        default:
           printf("Invalid operator sign\n");
           printf("Exiting from program\n");
           getch();
           exit(1);     
      }
      stack[++top]=r;  
    }                        
  }
  r=stack[top--];
    return r; 
}
int preeval(char *pre)
{
  int stack[100],top=-1;
  int i,op1,op2,r;
  for(i=strlen(pre)-1;i>=0;i--)
  {
    if(pre[i]>='0'&&pre[i]<='9') 
    {
      stack[++top]=pre[i]-48;                             
    }
    else
    {
      op1=stack[top--];
      op2=stack[top--];
      switch(pre[i])
      {
        case '+':
           r=op1+op2;
           break;
        case '-':                  
           r=op1-op2;
           break;
        case '*':                  
           r=op1*op2;
           break;
        case '/':                  
           r=op1/op2;
           break;
        case '%':                  
           r=op1%op2;
           break;
        case '^':                  
           r=(int)pow(op1,op2);
           break;   
        default:
           printf("Invalid operator sign\n");
           printf("Exiting from program\n");
           getch();
           exit(1);     
      }
      stack[++top]=r;  
    }                        
  }
  r=stack[top--];
  return r; 
}
