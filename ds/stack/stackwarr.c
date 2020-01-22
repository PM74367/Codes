#include <stdio.h>
#include <stdlib.h>

struct Stack 
{
unsigned  capacity;//no. of elements in stack
int * array;//array 
int top; 
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->array=(int*)malloc(sizeof(int)*capacity);
    stack->capacity=capacity;
    stack->top=-1;
    return stack;
}
//isempty
int isempty(struct Stack * stack)
{
    return stack->top==-1;
}
//isfull
int isfull(struct Stack * stack)
{
    return stack->top==stack->capacity-1;
}
//push 
void push(struct Stack*stack,int data)
{
    if(isfull(stack))
     {printf("Overflow condition\n"); return;}
    stack->array[++stack->top]=data;
    printf("%d pushed to stack\n",stack->array[stack->top]);
}
//pop
int pop(struct Stack*stack)
{
    if(isempty(stack))
    {printf("Underflow Condtion\n"); return -99;}
    printf("%d popped from stack\n",stack->array[stack->top]);
    return stack->array[stack->top--];

}
//peek
int peek(struct Stack*stack)
{
  if(isempty(stack))
  {printf("No element present\n"); return -99;}
  
  printf("%d is at the top\n",stack->array[stack->top]);
  return stack->array[stack->top]; 
}

void print(struct Stack *stack)
{
    int temp=stack->top;
 for(;temp>=0;temp--)
    printf("%d ",stack->array[temp]);
    printf("\n");
}

int main()
{
 struct Stack * stack=createStack(5);
 push(stack,10);
 push(stack,20);
 push(stack,30);

 peek(stack);
 pop(stack);
 print(stack);

 pop(stack);
 print(stack);
 
 pop(stack);
peek(stack);
}