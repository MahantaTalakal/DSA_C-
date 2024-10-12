#include<iostream>
#include<stdlib.h>

typedef struct dnode{
    dnode* right;
    int data;
    dnode* left;
}dnode;

dnode * create_node(int n){
    dnode* ptr=(dnode*)malloc(sizeof(dnode));
    ptr->data=n;
    ptr->left=NULL;
    ptr->right=NULL;
}

dnode* insert_front(dnode* head, int n){
    dnode* p=create_node(n);
    if(head==NULL) head=p;

    else{
        
        p->right=head;
        head->left=p;
        head=p;
    }

    return head;   
}

dnode* insert_last(dnode* head, dnode* last,int n){
    dnode* p=create_node(n);
    dnode* temp;
    if(head==NULL){
        head=p;
        last=p;
        return head;
        }
    
    else{
        temp= head;
        while(temp!=NULL){
            temp=temp->right;
        }

        temp->right=p;
        p->left=temp;
        p->right=NULL;      
    }
    return head;
}





int main(){

}