#include <stdio.h>
#include <stdlib.h>


struct Node 
{
int data;
struct Node * next;
struct Node * prev;
};
//insertbefore 
void insertbefore(struct Node **head_ref,struct Node * next_node,int data)
{
    if(next_node==NULL)
    {
        printf("next node can't be NULL\n");
        return ;
    }
    struct Node * node=(struct Node *)malloc(sizeof(struct Node ));
    node->data=data;

    node->next=next_node;
    node->prev=next_node->prev;
    next_node->prev=node;
    if(node->prev!=NULL)
        node->prev->next=node;
    else 
    {
        *head_ref=node;
    }
}

//insertafter 
void insertafter(struct Node * prev_node,int data)
{
    if(prev_node==NULL)
    {
        printf("prev can't be NULL\n");
        return; 
    }
    struct Node * node=(struct Node *)malloc(sizeof(struct Node ));
    node->data=data;

    node->prev=prev_node;
    node->next=prev_node->next;
    prev_node->next=node;
    if(node->next!=NULL)
        node->next->prev=node;
}
//append
void append(struct Node **head_ref,int data)
{
    struct Node * node=(struct Node *)malloc(sizeof(struct Node ));
    node->data=data;
    node->next=NULL;
    struct Node * last=*head_ref;
    if(*head_ref==NULL)
    {
        node->prev=NULL;
        *head_ref=node;
        return ;
    }
    while(last->next!=NULL)
        last=last->next;
    
    last->next=node;
    node->prev=last;
}
//push
void push(struct Node **head_ref,int data)
{
    struct Node * node=(struct Node *)malloc(sizeof(struct Node ));
    node->data=data;
    node->next=*head_ref;
    node->prev=NULL;

    if(*head_ref!=NULL)
        (*head_ref)->prev=node;
    
    *head_ref=node;
}

//printlist
void printlist(struct Node * head)
{   struct Node * prev;
    
    while(head!=NULL)
    {   prev=head;
        printf("%d->",head->data);
        head=head->next;
    }printf("NULL\n");
    printf("In Reverse Order\n");

    while(prev!=NULL)
    {
        printf("%d->",prev->data);
        prev=prev->prev;
    }printf("NULL\n");
}
//main
int main()
{
    struct Node * head=NULL;
    push(&head, 7);  
    push(&head, 1);  
    push(&head, 4);  
    
    insertbefore(&head, head->next, 8);  
  
    printf("Created DLL is: \n");  
    printlist(head);  
  
    append(&head, 6);  
    push(&head, 7);  
  
    push(&head, 1);  
    append(&head, 4);  
  
    insertafter(head->next, 8);  
  
    printf("Created DLL is: \n");  
    printlist(head);  
  
    return 0;  
}