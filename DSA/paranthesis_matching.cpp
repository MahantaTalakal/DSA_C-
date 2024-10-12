#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    char data;
    node* next;
} node;

node* head = NULL;
int stack_size = 0;

node* create_node(char n = 0) {
    node* ptr = (node*)malloc(sizeof(node));
    if (ptr != NULL) {
        ptr->next = NULL;
        ptr->data = n;
    }
    return ptr;
}

void push(char n) {
    node* temp = create_node(n);
    if (temp == NULL) {
        cout << "Overflow." << endl;
        return;
    }
    temp->next = head;
    head = temp;
    stack_size++;
}

void pop() {
    if (stack_size == 0) {
        cout << "Underflow." << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    free(temp);
    stack_size--;
}

int isEmpty() {
    return (head == NULL);
}

int isFull() {
    node* temp = create_node();
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

char peek() {
    if (head == NULL) {
        cout << "Stack is empty." << endl;
        return '\0'; 
    }
    return head->data;
}

void display() {
    if (head == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void free_stack() {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int param_match(char* ch) {
    int count_closedParam = 0; // Counter for unmatched closing parentheses/braces
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{') {
            push(ch[i]); // Push corresponding opening brace to the stack
        } else if (ch[i] == ')' || ch[i] == ']' || ch[i] == '}') {
            if (stack_size == 0) {
                count_closedParam--; // No matching opening brace
            } else {
                char top = peek();
                if ((ch[i] == ')' && top == '(') ||
                    (ch[i] == ']' && top == '[') ||
                    (ch[i] == '}' && top == '{')) {
                    pop(); // Matching brace found, pop from stack
                } else {
                    count_closedParam--; // Unmatched closing brace
                }
            }
        }
    }
    if (count_closedParam) return count_closedParam; // Return unmatched closing braces
    return stack_size; // Return unmatched opening braces if any
}

int main() {
    char ch[] = "{((a+b)*(c/d)))))}";
    int balanced = param_match(ch);

    if (balanced > 0) {
        cout << balanced << " more opening brace(s) than closing brace(s)." << endl;
    } else if (balanced < 0) {
        cout << -balanced << " more closing brace(s) than opening brace(s)." << endl;
    } else {
        cout << "Parentheses/braces are balanced." << endl;
    }
    
    free_stack();
    return 0;
}
