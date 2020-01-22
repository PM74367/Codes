#include <stdlib.h>
#include <stdio.h>

struct Node 
{
    int data;
    struct Node * next;
};
//empty
struct Node * empty(struct Node * last,int data)
{
    if(last!=NULL)
        return last;
    struct Node * newnode=(struct Node * )malloc(sizeof(struct Node ));
    newnode->data=data;
    newnode->next=newnode;
    return newnode;
}

//append 
struct Node * append(struct Node * last,int data)
{
 if(last==NULL)
        return empty(last,data);
    struct Node * newnode=(struct Node * )malloc(sizeof(struct Node ));
    newnode->data=data;   
    newnode->next=last->next;
    last->next=newnode;
    last=newnode;
    return last;
}
//push 
struct Node * push(struct Node * last,int data)
{
 if(last==NULL)
        return empty(last,data);
    struct Node * newnode=(struct Node * )malloc(sizeof(struct Node ));
    newnode->data=data;  
    newnode->next=last->next;
    last->next=newnode;
    return last;
}
//insertafter 
struct Node * insertafter(struct Node *last,int data,int item)
{
    if(last==NULL)
        return empty(last,data);
    
    struct Node * temp=last->next;
    do
    {   if(temp->data==item)
        {
               struct Node * newnode=(struct Node * )malloc(sizeof(struct Node ));
                newnode->data=data;
                newnode->next=temp->next;
                temp->next=newnode;
                if(temp==last)
                    last=newnode;
                return last;
        }
        temp=temp->next;
    } while (temp!=last->next);

    printf("Item not found\n");
    return last;
}
//printlist 
void printlist(struct Node * last)
{
    if(last==NULL)return ;
    struct Node * head=last->next;
    do
    {
        printf("%d->",head->data);
        head=head->next;
    } while (head!=last->next);
    printf("NULL\n");
}

//main 
int main()
{
    struct Node * last=NULL;
    last=empty(last,10);
    last=push(last,20);
    last=push(last,30);
    last=insertafter(last,40,10);
    last=append(last,50);
    printlist(last);
    return 0;
}