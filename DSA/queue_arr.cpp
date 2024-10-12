#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct queue_arr
{
    int size;
    int front; int rear;
    int * Q;
}queue_arr;

void create_queue(queue_arr& ptr,int n){
    int *p=(int *)malloc(n*sizeof(int));
    ptr.front=-1;
    ptr.rear=-1;
    ptr.size=n;
    ptr.Q = p;
}

void enqueue(queue_arr& q,int n){
    if(q.rear==q.size-1) {cout<<"queue is full<<endl"; return;
}
    q.rear++;
    q.Q[q.rear]=n;
}

void dequeue(queue_arr& q){
    if(q.front==q.rear) {cout<<"queue is empty"<<endl; return;}
    int temp=q.front;
    q.front++;
    int x=q.Q[q.front];
    cout<<"the element"<< x<<" has been dequeued."<<endl;
    return;
}

void disp(queue_arr& q){
    for(int i=q.front+1;i<q.size;i++){
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
};

int getFront(queue_arr& q){
    return q.Q[q.front+1];
}

void delete_queue(queue_arr& q) {
    free(q.Q);
}


int main() {
    queue_arr q;
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;
    create_queue(q, n);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    disp(q);  // Expected output: 10 20 30

    dequeue(q);
    disp(q);  // Expected output: 20 30

    cout << "Front element is: " << getFront(q) << endl;  // Expected output: 20

    delete_queue(q);
    return 0;
}