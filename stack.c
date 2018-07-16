#define size 5
struct stack
{
   int st[size],top;    
};
void push(struct stack *p);
void pop(struct stack *p);
void peek(struct stack p);

void main()
{
  struct stack s1;
  s1.top=-1;
  int choice;
  do
  {
    printf("press 1 for push\n");
    printf("press 2 for pop\n");
    printf("press 3 for peek\n");
    printf("Press 4 for exit\n");
    printf("Press ur choice\n");
    scanf("%d",&choice);
    switch(choice) 
    {
      case 1:
        push(&s1);
        break;
      case 2:
        pop(&s1);
        break;
      case 3:
        peek(s1);
        break;
      case 4:
        printf("Exiting from program");
        break;
      default:
        printf("Invalid choice");                                        
    } 
    
  }while(choice!=4);   
  
}
void push(struct stack *p)
{
    int item;
    if(p->top==size-1)
    {
      printf("Overflow\n");
      return;            
    } 
    printf("Enter the item\n");
    scanf("%d",&item);
    p->top++;
    p->st[p->top]=item;
    printf("Item inserted in stack\n");
}
void pop(struct stack *p)
{
    int item;
    if(p->top==-1)
    {
      printf("Underflow\n");
      return;            
    } 
    item=p->st[p->top];
    p->top--;
    printf("Item(%d)deleted from stack\n",item);
}
void peek(struct stack p)
{
    int item;
    if(p.top==-1)
    {
      printf("empty stack\n");
      return;            
    } 
    item=p.st[p.top];
    printf("Peek Item(%d) in stack\n",item);   
}
