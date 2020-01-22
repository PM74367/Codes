#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack * next;
};
//createnode
struct Stack * createnode(int data)
{
    struct Stack* newnode=(struct Stack*)malloc(sizeof(struct Stack));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
//push
void push(struct Stack **root,int data)
{
    struct Stack *newnode=createnode(data);
    newnode->next=*root;
    *root=newnode;
    printf("%d is pushed \n",(*root)->data);
}

//isempty
int isempty(struct Stack * root)
{
    return !root;
}
//pop
int pop(struct Stack**root)
{   if(isempty(*root))
    {
        printf("underflow\n");
        return -99;
    }

    struct Stack * temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    printf("%d is popped\n",popped);
    free(temp);
}
//peek
int peek(struct Stack *root)
{
    if(isempty(root))
    {
        printf("no value present\n");
    return -99;
    }
    printf("top is at %d\n",root->data);
    return root->data;

}


int main()
{
 struct Stack * root=NULL;
 //use of double pointer is to change the root node in main 
 push(&root,10);
 push(&root,20);
 push(&root,30);
 peek(root);
 pop(&root);
 pop(&root);
 pop(&root);
 peek(root);
 pop(&root);
 return 0;
}
