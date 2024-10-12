#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct treeNode{
    treeNode* leftChild;
    int data;
    treeNode* rightChild;
}treeNode;

typedef struct Queue
{
 int size;
 int front;
 int rear;
treeNode* *Q;

}Queue;

void create(struct Queue *q,int size)
{
 q->size=size;
 q->front=q->rear=0;
 q->Q=(treeNode **)malloc(q->size*sizeof(treeNode*));
}
void enqueue(struct Queue *q,treeNode*x)
{
 if((q->rear+1)%q->size==q->front)
 printf("Queue is Full\n");
 else
 {
 q->rear=(q->rear+1)%q->size;
 q->Q[q->rear]=x;
 }
}
treeNode* dequeue(struct Queue *q)
{
 treeNode* x=NULL;

 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front=(q->front+1)%q->size;
 x=q->Q[q->front];
 }
 return x;
}
void Display(struct Queue q)
{
 int i=q.front+1;

 do
 {

 printf("%d ",q.Q[i]);
 i=(i+1)%q.size;
 }while(i!=(q.rear+1)%q.size);

 printf("\n");
}

int isEmpty(Queue *q){
    return q->front==q->rear;
}