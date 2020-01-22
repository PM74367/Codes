#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};

//push
void push(struct Node **head,int data)
{
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

//insertafter
void insertafter(struct Node * prev,int data)
{
    if(prev==NULL)
      {  
          printf("Node cannot be null \n");
      }
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=prev->next;
    prev->next=newnode;
}
//append
void append(struct Node **head,int data)
{
    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));
    struct Node *last=*head;
    newnode->next=NULL;
    newnode->data=data;
    if(*head==NULL)
    {
        *head=newnode;
        return ;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
    return ;
}
//printlist
void printlist(struct Node * head)
{
    
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }printf("NULL\n");
}
//main
/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */


struct Node * shiftSmallLarge(struct Node *org)
{	
 	struct Node *s=org;
    struct Node * ps;
   struct Node * l;
   struct Node *pl;
	struct Node * temp=org->next;
    struct Node * last;
    struct Node * head=org;
//finding smallest and pushing node 

  	while(temp!=NULL)
    {
      if(s->data > temp->data)
       {
           ps=last; 
           s=temp;
       }
       last=temp;
      temp=temp->next;
    }
    if(s!=org)
   { struct Node * small=(struct Node *)malloc(sizeof(struct Node));
    small->next=org;
    small->data=s->data;
    ps->next=s->next;
    free(s);
   
//finding largest and appending node 
    temp=small->next;
    last=small;
    l=small->next;
    pl=small;
    head=small;
   }
   else
   {
       temp=org->next;
       last=org;
        l=org->next;
    pl=org;
    head=org;
   }
   
   
   while(temp!=NULL)
   {
       if(l->data < temp->data)
       {
           pl=last;
           l=temp;
       }
        last=temp;
        temp=temp->next;
   }
   if(l!=last)
   {
    struct Node * large=(struct Node *)malloc(sizeof(struct Node));
    large->next=NULL;
    large->data=l->data;
    pl->next=l->next;
    last->next=large;
    free(l);
   } 
    return head;

}
int main()
{
    struct Node * head=NULL;
    append(&head,2);
    push(&head,7);
    push(&head,1);
    append(&head,4);
    insertafter(head,8);
    printlist(head);
    head=shiftSmallLarge(head);
    printlist(head);
    return 0;
}