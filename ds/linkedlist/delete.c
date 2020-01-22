#include <stdlib.h>
#include <stdio.h>

struct Node 
{
    int data;
    struct Node * next;
};

void push(struct Node **head,int data)
{
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
//delte first occurence of key
void deletenode(struct Node **head,int key)
{   
    if(*head==NULL)return;
    
    struct Node*temp=*head,*prev;
    
    if(temp->data==key)
    {
        *head=(*head)->next;
        free(temp);
        return ;
    }

    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)return ;//as no element is found and list is exhausted

    prev->next=temp->next;

    free(temp);
    
}
//delte position
void deletepos(struct Node **head,int position)
{
    if(head==NULL)return ;

    struct Node *temp=*head,*prev;

    if(position==0)
       { 
           *head=(*head)->next;
           free(temp);
           return ;
       }
    
    for(int i=0;temp!=NULL && i<position;i++)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){printf("\tList Exhausted");return;}

    prev->next=temp->next;
    
    free(temp);
}

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d->", node->data); 
        node = node->next; 
    }printf("NULL");
    printf("\n");
} 

int main()
{
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
   
    printf("List is :");printList(head);
    deletenode(&head,3);

    printList(head);
    deletepos(&head,3);
    
    printList(head);
    deletepos(&head,0);
    printList(head);
    return 0;
}