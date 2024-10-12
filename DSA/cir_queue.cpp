#include <iostream>
#include <stdlib.h>

using namespace std;

class cir_queue {
    int front;
    int rear;
    int size;
    int *q;

public:
    cir_queue(int size) {
        front = 0;
        rear = 0;
        this->size = size;
        q = (int*)malloc(sizeof(int) * size);
    }

    void enqueue(int n) {
        if (((this->rear + 1) % this->size) == this->front) {
            cout << "The queue is full" << endl;
            return;
        }

        this->rear = (this->rear + 1) % this->size;
        q[this->rear] = n;
    }

    void dequeue() {
        if (this->front == this->rear) {
            cout << "The queue is empty." << endl;
            return;
        }

        this->front = (this->front + 1) % this->size;
        cout << q[this->front] << " is removed from the list." << endl;
    }

    int getFront() {
        return q[(front + 1) % size];
    }

    int isFull() {
        return ((rear + 1) % size == front);
    }

    void disp() {
        if (front == rear) {
            cout << "The queue is empty." << endl;
            return;
        }
        int i = (front + 1) % size;
        while (i != (rear + 1) % size) {
            cout << q[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    cir_queue q(5); // Example size of 5

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.disp();

    q.dequeue();
    q.disp();

    q.enqueue(5);
    q.disp();

    q.dequeue();
    q.disp();

    return 0;
}
