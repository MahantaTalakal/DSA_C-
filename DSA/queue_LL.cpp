#include <iostream>
#include <stdlib.h>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int n) {
        this->data = n;
        this->next = NULL;
    }
};

class queue {
    node* head;
    node* tail;
    int size;

public:
    queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int data) {
        // Use malloc for memory allocation
        node* newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            cout << "Memory allocation failed" << endl;
            return;
        }
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
        size--;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int getFront() {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return -1; // Return an error value
        }
        return head->data;
    }

    void displayQueue() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; // Newline for better output formatting
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.displayQueue(); // Expected output: 10 20 30

    q.dequeue();
    q.displayQueue(); // Expected output: 20 30

    cout << "Front element is: " << q.getFront() << endl; // Expected output: 20

    return 0;
}
