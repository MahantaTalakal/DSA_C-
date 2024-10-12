#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    node* next;
} node;

node* create_node(int n) {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->next = NULL;
    ptr->data = n;
    return ptr;
}

typedef struct stack_LL {
    node* head = NULL;
    int size = 0;
    int capacity;
} stack_LL;

void push(stack_LL& stack, int n) {
    if (stack.size == stack.capacity) {
        cout << "Overflow." << endl;
        return;
    }
    node* temp = create_node(n);
    temp->next = stack.head;
    stack.head = temp;
    stack.size++;
}

void pop(stack_LL& stack) {
    if (stack.size == 0) {
        cout << "Underflow." << endl;
        return;
    }
    node* temp = stack.head;
    stack.head = stack.head->next;
    cout << temp->data << " is removed from the stack." << endl;
    free(temp);
    stack.size--;
}

int isEmpty(stack_LL& stack) {
    return (stack.head == NULL);
}

int isFull(stack_LL& stack) {
    return (stack.size == stack.capacity);
}

int peek(stack_LL& stack) {
    if (stack.head == NULL) {
        cout << "Stack is empty." << endl;
        return -1; // Sentinel value indicating the stack is empty
    }
    return stack.head->data;
}

void display(stack_LL& stack) {
    if (stack.head == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    node* temp = stack.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void free_stack(stack_LL& stack) {
    node* temp;
    while (stack.head != NULL) {
        temp = stack.head;
        stack.head = stack.head->next;
        free(temp);
    }
}

int main() {
    stack_LL stack;
    cout << "Enter max capacity of the stack: ";
    cin >> stack.capacity;

    int choice, n;

    do {
        cout << "Enter your choice: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if stack is empty" << endl;
        cout << "4. Check if stack is full" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Display stack" << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> n;
                push(stack, n);
                break;
            
            case 2:
                pop(stack);
                break;

            case 3:
                if (isEmpty(stack))
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 4:
                if (isFull(stack))
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;

            case 5:
                n = peek(stack);
                if (n != -1)
                    cout << "Top element is: " << n << endl;
                break;

            case 6:
                display(stack);
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    free_stack(stack);
    return 0;
}
