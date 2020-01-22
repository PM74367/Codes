#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
};
//deletenode
void deletenode(struct Node **head_ref,struct Node * del)
{
    if(*head_ref==NULL || del==NULL)
        return ;
    
    if(*head_ref==del)
        *head_ref=del->next;
    
    if(del->next!=NULL)
        del->next->prev=del->prev;
    
    if(del->prev!=NULL)
        del->prev->next=del->next;

    free(del);
}

//deletepos
void deletepos(struct Node **head_ref,int pos)
{
    struct Node *temp=*head_ref;
    struct Node * prev;
    if(*head_ref==NULL || pos<0)
        return;

    if(pos==0)
        {
            *head_ref=temp->next;       
            return;
        }
    
    for(int i=0;temp!=NULL && i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }

    if(temp==NULL)return ;//list shorter than position 

    //temp->prev->next=temp->next;
    prev->next=temp->next;
    
    if(temp->next!=NULL)
        temp->next->prev=prev;
        //temp->next->prev=temp->prev;

    free(temp);
}


//push
void push(struct Node **head_ref,int data)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->next=*head_ref;
    node->prev=NULL;
    if(*head_ref!=NULL)
        (*head_ref)->prev=node;
    *head_ref=node;
}

//printlist
void printlist(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d->", node->data); 
        node = node->next; 
    }printf("NULL");
    printf("\n");
} 
//main
int main()
{
    struct Node * head=NULL;
    push(&head, 5); 
    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 

   printlist(head);
   
   deletenode(&head,head->next);
    printlist(head);
   
   deletepos(&head,0);
    printlist(head);
   
   deletepos(&head,1);
    printlist(head);
    return 0;
}