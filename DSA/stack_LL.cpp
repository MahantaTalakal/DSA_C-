#include<iostream>
#include<stdlib.h>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int n) {
        this->data = n;
        this->next = nullptr;
    }
};

class stack_LL {
    node* head;
    int capacity;
    int current_size;

public:
    stack_LL(int c) {
        this->capacity = c;
        this->current_size = 0;
        this->head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return current_size == capacity;
    }

    void push(int n) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }

        node* new_node = (node*)malloc(sizeof(node));
        if (new_node == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }
        new_node->data = n;
        new_node->next = head;
        head = new_node;
        current_size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        node* temp = head;
        head = head->next;
        int popped = temp->data;
        cout << temp->data << " is removed from the stack" << endl;
        free(temp);
        current_size--;
        return popped;
    }

    int get_top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    stack_LL Stack(10);
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.push(40);
    cout << Stack.get_top() << endl;
    Stack.pop();
    cout << Stack.get_top() << endl;
    Stack.push(89);
    cout << Stack.get_top() << endl;

    return 0;
}
