#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node{
    node* prev;
    int data;
    node*next;
}node;

node* create_node(int n){
    node*p=(node*)malloc(sizeof(node));
    p->data=n;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

node* insert_front(node* head,int n){
    node*p=create_node(n);
    if(head!=NULL){
    p->next=head;
    head->prev=p;
    p->prev=NULL;
    }
    head=p;
    return head;
}

node* insert_end(node* head,int n){

    if(head==NULL) return insert_front(head,n);
    else{
    node* ptr=head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    node*p=create_node(n);
    ptr->next=p;
    p->next=NULL;
    p->prev=ptr;
    return head;}
}

node* insert_index(node* head, int index, int n) {
    if (index < 0) {
        cout << "Index out of bounds" << endl;
        return head;
    }

    if (index == 0) {
        return insert_front(head, n);  // Insert at the front
    } else {
        node* p = create_node(n);  // Create a new node
        if (p == NULL) {
            // Handle memory allocation failure
            cout << "Memory allocation failed!" << endl;
            return head;
        }

        node* ptr = head;
        for (int i = 0; i < index - 1 && ptr != NULL; i++) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            // Index is out of bounds
            cout << "Index out of bounds" << endl;
            free(p);  // Free memory allocated for p
            return head;
        }

        p->next = ptr->next;  // Link the new node
        p->prev = ptr;
        if (ptr->next != NULL) {
            ptr->next->prev = p;
        }
        ptr->next = p;

        return head;
    }
}
