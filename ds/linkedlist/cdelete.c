// C program to delete a given key from 
// linked list. 
#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int data) 
{ 
	// Create a new node and make head as next 
	// of it. 
	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
	ptr1->data = data; 
	ptr1->next = *head_ref; 

	/* If linked list is not NULL then set the 
	next of last node */
	if (*head_ref != NULL) { 
		// Find the node before head and update 
		// next of it. 
		struct Node* temp = *head_ref; 
		while (temp->next != *head_ref) 
			temp = temp->next; 
		temp->next = ptr1; 
	} 
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1; 
} 

void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	if (head != NULL) { 
		do { 
			printf("%d ", temp->data); 
			temp = temp->next; 
		} while (temp != head); 
	} 

	printf("\n"); 
} 

/* Function to delete a given node from the list */
void deleteNode(struct Node**head, int key) 
{ 
	if (head == NULL) 
		return; 

	struct Node *curr =*head, *prev; 
	struct Node * temp=*head;
	struct Node * last;
	    //finding last node 
	 
	
	if((*head)->data==key)//deleting first node 
	{
	       do
	    {
	        temp=temp->next;
	    }   while(temp->next!=*head);
	    
	    printf("last node is %d\n",temp->data);
	   
	    *head=(*head)->next;
	    free(temp->next);
	    temp->next=*head;
	    return;
	}

	do 
	{
	 prev=curr;
	 curr=curr->next;
	}while(curr->data!=key && curr->next!=*head);
	
	if(curr->data==key && curr->next==*head)//if the last node is the key 
	{
	   prev->next=*head;
	   free(curr);
	   return;
	}
	
    if(curr->next==*head)//if we didn't find the key 
        {
            printf("no node found\n");
            return; 
        }
        
    prev->next=curr->next;
    free(curr);
    return;
	
} 

/* Driver program to test above functions */
int main() 
{ 
	/* Initialize lists as empty */
	struct Node* head = NULL; 

	/* Created linked list will be 2->5->7->8->10 */
	push(&head, 2); 
	push(&head, 5); 
	push(&head, 7); 
	push(&head, 8); 
	push(&head, 10); 

	printf("List Before Deletion: "); 
	printList(head); 
    int x;
    scanf("%d",&x);
	deleteNode(&head, x); 

	printf("List After Deletion: "); 
	printList(head->next); 

	return 0; 
} 
