#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct queue_arr
{
    int size;
    int front;
    int rear;
    int * Q;
}queue_arr;

void createQueue(queue_arr& q, int s){
    q.front = q.rear = -1;
    q.size = s;
    q.Q = (int*)malloc(sizeof(int) * q.size);
}

void Pushrear(queue_arr& q, int n){
    if (((q.rear + 1) % q.size == q.front) || (q.front == 0 && q.rear == q.size - 1)){
        cout << "The queue is full" << endl;
        return;
    }

    if (q.front == -1 && q.rear == -1){
        q.front = q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % q.size;
    }
    q.Q[q.rear] = n;
}

void PushFront(queue_arr& q, int n){
    if (((q.rear + 1) % q.size == q.front) || (q.front == 0 && q.rear == q.size - 1)){
        cout << "The queue is full" << endl;
        return;
    }

    if (q.front == -1 && q.rear == -1){
        q.front = q.rear = 0;
    } else if (q.front == 0) {
        q.front = q.size - 1;
    } else {
        q.front--;
    }
    q.Q[q.front] = n;
}

void popfront(queue_arr& q){
    if (q.front == -1 && q.rear == -1){
        cout << "The queue is empty" << endl;
        return;
    }

    if (q.front == q.rear){
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % q.size;
    }
}

void poprear(queue_arr& q){
    if (q.front == -1 && q.rear == -1){
        cout << "The queue is empty" << endl;
        return;
    }

    if (q.front == q.rear){
        q.front = q.rear = -1;
    } else if (q.rear == 0){
        q.rear = q.size - 1;
    } else {
        q.rear--;
    }
}

void disp(queue_arr& q){
    if (q.front == -1 && q.rear == -1){
        cout << "No elements to display" << endl;
        return;
    }

    int f = q.front;
    int r = q.rear;

    if (f <= r) {
        while (f <= r) {
            cout << q.Q[f] << " ";
            f++;
        }
    } else {
        while (f < q.size) {
            cout << q.Q[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r) {
            cout << q.Q[f] << " ";
            f++;
        }
    }
    cout << endl;
}

int main() {
    queue_arr q;
    createQueue(q, 5);

    Pushrear(q, 10);
    Pushrear(q, 20);
    PushFront(q, 5);
    Pushrear(q, 30);

    disp(q);

    popfront(q);
    disp(q);

    poprear(q);
    disp(q);

    return 0;
}
