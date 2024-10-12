#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    node* next;
} node;

node* head = NULL;
node* rear = NULL;
int size = 0;

node* create_node(int n) {
    node* p = (node*)malloc(sizeof(node));
    p->data = n;
    p->next = NULL;
    return p;
}

void enqueue(int n) {
    node* ptr = create_node(n);
    if (ptr == NULL) {
        cout << "Queue is full" << endl;
        return;
    }
    if (head == NULL) {
        head = ptr;
        rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    size++;
}

void dequeue() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    } else {
        node* temp = head;
        head = head->next;
        cout << temp->data << " has been removed from the queue." << endl;
        free(temp);
        size--;
        if (head == NULL) {
            rear = NULL; 
        }
    }
}

void emptyQueue(){
    node* temp=head;
    while(head!=NULL){
        head=head->next;
        free(temp);
        temp=head;
    }
    if(head==NULL) cout<<"The queue has been emptied."<<endl;
}

void disp(){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}