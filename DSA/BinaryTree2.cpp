#include <iostream>
#include <stdlib.h>
#include "header/queue_LL.h"

using namespace std;

Tnode* root=NULL;

void CreateTree(){
    Tnode* p,*t;
    int x;

    cout<<"enter the root node value :";
    root=(Tnode*)malloc(sizeof(Tnode));
    cin>>root->n;
    root->left=root->right=NULL;

    enqueue(root);

    while(!isEmpty()){
        p=dequeue();
        cout<<"enter the left child of "<<p->n<<" : ";
        cin>>x;

        if(x!=-1){
            t=(Tnode*)malloc(sizeof(Tnode));
            t->left=t->right=NULL;
            t->n=x;
            p->left=t;
            enqueue(t);
        }

        cout<<"enter the right child of "<<p->n<<" : ";
        cin>>x;

        if(x!=-1){
            t=(Tnode*)malloc(sizeof(Tnode));
            t->left=t->right=NULL;
            t->n=x;
            p->right=t;
            enqueue(t);
    }
}
}

void preorder(Tnode* q) {
    if (q) {
        cout << q->n << " ";
        preorder(q->left);
        preorder(q->right);
    }
}

int main(){
    CreateTree();
    preorder(root);
}
