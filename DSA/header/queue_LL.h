#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Tnode{
    Tnode *left;
    Tnode*right;
    int n;
}Tnode;

typedef struct node{
    Tnode* data;
    node*next;
}node;

node* head=NULL;
node* tail=NULL;

node* create_node(Tnode* n){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
}

void enqueue(Tnode* n){
    node* ptr=create_node(n);
    if(ptr==NULL){
        return;
    }
    if(head==NULL){
        head=tail=ptr;
    }
    else{
        tail->next=ptr;
        tail=ptr;
    }
}

Tnode* dequeue(){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    Tnode* x=temp->data;
    head=head->next;
    free(temp);
    return x;
}

int isEmpty(){
    return head==NULL;
}
