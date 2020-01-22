#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int rear,front,size;
    unsigned capacity;
    int *arr;
};
//isempty
int isEmpty(struct  Queue *q)
{
    if(q->size==0)return 1;
    else return 0;
}

//isfull
int isFull(struct Queue *q)
{
    if(q->size==q->capacity)
        return 1;
    else return 0;
}

struct Queue* createq(unsigned capacity)
{
    struct Queue * q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=capacity;
    q->rear=capacity-1;
    q->front=0,q->size=0;
    q->arr=(int*)malloc(sizeof(int)*q->capacity);
    return q;
}

//insertfront
void insertfront(struct Queue*q,int item)
{
    if(isFull(q))
        printf("Overflow\n");
    else
    {
        if(q->front==0)
            q->front=q->capacity-1;
        else 
            q->front--;

        q->arr[q->front]=item;
        q->size++;    
    }
}

//insertend
void insertend(struct Queue*q,int item)
{
    if(isFull(q))
        printf("Overflow");
    else
    {
        q->rear=(q->rear+1)%q->capacity;
        q->arr[q->rear]=item;
        q->size++;
    }
}

//deletefront
void deletefront(struct Queue*q)
{
    if(isEmpty(q))
        printf("Underflow\n");
    else
    {
        q->front=(q->front+1)%q->capacity;
        q->size--;
    }    
}
//deleteend
void deleteend(struct Queue *q)
{
    if(isEmpty(q))
        printf("Underflow\n");
    else 
    {
        if(q->rear==0)
            q->rear==q->capacity-1;
        else
            q->rear--;
        q->size--;
    }
}
//getfront
void getfront(struct Queue*q)
{
    if(isEmpty(q))
        printf("No Elements\n");
    else 
        printf("Front at : %d\n",q->arr[q->front]);
}
//getend
void getend(struct Queue*q)
{
    if(isEmpty(q))
        printf("No Elements\n");
    else 
        printf("End at : %d\n",q->arr[q->rear]);
}


int main()
{
    struct Queue*queue=createq(5);
    /*insertend(queue,5);
    insertend(queue,10);
    getend(queue);
    
    deleteend(queue);
    getend(queue);
    
    deleteend(queue);
    getend(queue);*/

    insertfront(queue,15);
    getfront(queue);
    getend(queue);
    insertfront(queue,20);
    getfront(queue);
    getend(queue);


    deleteend(queue);
    getfront(queue);
    getend(queue);
    
    deleteend(queue);
      getfront(queue);
    getend(queue);
    
    return 0;
}