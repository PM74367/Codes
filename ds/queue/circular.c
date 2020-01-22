#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front,rear,size;
    unsigned int capacity;
    int * array;
};

struct queue* createqueue(unsigned int capacity)
{
    struct queue* q=(struct queue *)malloc(sizeof(struct queue));
    q->front=q->size=0;
    q->rear=capacity-1;
    q->capacity=capacity;
    q->array=(int*)malloc(sizeof(int)*q->capacity);
    return q;
}

int isFull(struct queue*q)
{
    if(q->size==q->capacity)
    { printf("overflow\n");
        return 1;}
    else return 0;
}

int isEmpty(struct queue*q)
{
    if(q->size==0)
   { printf("underflow\n");
        return 1;}
    else return 0;
}
int front(struct queue *q)
{   if(isEmpty(q))return 1;
    return q->array[q->front];
}
int rear(struct queue*q)
{   if(isEmpty(q))return 1;
    return q->array[q->rear];
}

void enqueue(struct queue*q,int item)
{
    
    if(isFull(q))return ;
    printf("%d is enqueued\n",item);
    q->size++;
    q->rear=(q->rear+1)%q->capacity;
    q->array[q->rear]=item;
}

int dequeue(struct queue*q)
{
    if(isEmpty(q))return 99 ;
    q->size--;
    int item=q->array[q->front];
    q->front=(q->front+1)%q->capacity;
    return item;
}

int main()
{
    struct queue*q=createqueue(5);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
   
    printf("item removed is %d\n",dequeue(q));
    printf("item removed is %d\n",dequeue(q));
    printf("item removed is %d\n",dequeue(q));
    printf("item removed is %d\n",dequeue(q));
   
    enqueue(q,40);
    enqueue(q,50);
    printf("item removed is %d\n",dequeue(q));
    printf("item removed is %d\n",dequeue(q));
    enqueue(q,50);
    printf("rear is at %d\n",q->rear);
    printf("front is at %d\n",q->front);
    

}