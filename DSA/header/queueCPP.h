#include<iostream>
#include<stdlib.h>

using namespace std;

class Tnode{
    public:
    Tnode* left;
    Tnode* right;
    int x;

    Tnode(int n){
        this->left=this->right=NULL;
        this->x=n;
    }
};

class node{
    public:
    Tnode* data;
    node* next;

    node(Tnode* n){
        this->data=n;
        this->next=NULL;
    }
};

class queue{
    private:
    node*head;
    node* tail;

    public: 
    queue(){
        this->head=NULL;
        this->tail=NULL;
    }

    void enqueue(Tnode* n){
        node* ptr= new node(n);
        if(ptr==NULL) return;

        if(head==NULL){
            this->head=ptr;
            this->tail=ptr;
        }
    else{
        tail->next=ptr;
        tail=ptr;}
    }

    Tnode* dequeue(){
        node*temp=this->head;
        Tnode* x=temp->data;
        head=head->next;
        free(temp);
        return(x);
    }

    int isEmpty() {
    return head == NULL;
    }
};