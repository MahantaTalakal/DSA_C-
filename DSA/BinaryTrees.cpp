#include <iostream>
#include <stdlib.h>
#include<stack>
#include<queue>
#include"header/queue_arr.h"



using namespace std;

treeNode* root=NULL;

void Treecreate(){
    treeNode* p,*t;
    int x;
    Queue q;
    create(&q,100);

    cout<<"enter value in root node: ";
    cin>>x;

    root=(treeNode* )malloc(sizeof(treeNode));
    root->data=x;
    root->leftChild=NULL;
    root->rightChild=NULL;

    enqueue(&q,root);

    while (!isEmpty(&q))        
    {
        p=dequeue(&q);
        cout<<"enter left child of "<<p->data<<" :";
        cin>>x;

        if(x!=-1){
            t=(treeNode* )malloc(sizeof(treeNode));
            t->data=x;
            t->leftChild=t->rightChild=NULL;
            p->leftChild=t;
            enqueue(&q,t);
        }
        
        cout<<"enter right child of "<<p->data<<" :";
        cin>>x;

        if(x!=-1){
            t=(treeNode* )malloc(sizeof(treeNode));
            t->data=x;
            t->rightChild=t->leftChild=NULL;
            p->rightChild=t;
            enqueue(&q,t);
        }

    }
}

void preorder(treeNode* q){
    if (q){
        cout<<q->data<<" ";
        preorder(q->leftChild);
        preorder(q->rightChild);
    }
}

void Ipreorder(treeNode* root){
    if (root == nullptr) {
        return; 
    }

    stack<treeNode*> stk;
    treeNode* p = root;

    while (p || !stk.empty()) {
        if (p) {
            cout << p->data << " "; 
            stk.emplace(p); 
            p = p->leftChild; 
        } else {
            p = stk.top();
            stk.pop();
            p = p->rightChild; 
        }
    }
}

void Iinorder(treeNode* root){
    if (root == nullptr) {
        return; // If the root is null, there's nothing to traverse.
    }

    stack<treeNode*> stk;
    treeNode* p = root;

    while (p || !stk.empty()) {
        if (p) {
            
            stk.emplace(p); 
            p = p->leftChild; 
        } else {
            p = stk.top();
            cout << p->data << " "; 
            stk.pop();
            p = p->rightChild;
        }
    }
}

void levelorder(treeNode* root){
    if (root == nullptr) {
        return;
    }
    queue<treeNode*> q;
    treeNode* p = root;
    q.emplace(p);

    while(! q.empty()){
        p=q.front();
        q.pop();

        cout<<p->data<<" ";

        if(p->leftChild){
            q.emplace(p->leftChild);
        }

        if(p->rightChild){
            q.emplace(p->rightChild);
        }
    }

}

int searchInorder(int InArray[], int Start, int End, int data){
    for(int i=Start;i<=End;i++){
        if(InArray[i]==data){
            return i;
        }
    }
    return -1;
}

treeNode* genTree(int *inorder, int *preorder, int inStart, int inEnd){
    static int preindex=0;

    if(inStart>inEnd) return nullptr;

    treeNode* node=(treeNode*)malloc(sizeof(treeNode));
    node->data=preorder[preindex++];
    node->leftChild = node->rightChild = nullptr;

    if (inStart == inEnd){
        return node;
    }

    int splitIndex=searchInorder(inorder, inStart, inEnd, node->data);
    node->leftChild=genTree(inorder,preorder,inStart,splitIndex-1);
    node->rightChild=genTree(inorder,preorder,splitIndex+1,inEnd);

    return node;
}

int main(){
    Treecreate();
    Ipreorder(root);
    cout<<endl;
    Iinorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;

    int Preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    treeNode* t=genTree(inorder,Preorder,0,(sizeof(inorder)/sizeof(int))-1);
    Ipreorder(t);
}
