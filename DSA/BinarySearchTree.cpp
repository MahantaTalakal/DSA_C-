#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>

using namespace std;

class treeNode{
    public:
    treeNode* leftChild;
    int data;
    treeNode*rightChild;

    treeNode(int n){
        rightChild=leftChild=NULL;
        this->data=n;
    }

};

class BST{
    public:
    treeNode* root;

    BST(){
        this->root=NULL;
    }

    void InsertNode(int n){

        treeNode* temp1=NULL;
        treeNode *temp2=NULL;

        temp1=temp2=root;
        
        while(temp1!=NULL){

           temp2=temp1;

           if(n==temp1->data) return;

           else{
            if(n>temp1->data) temp1=temp1->rightChild;

            else temp1=temp1->leftChild;
           } 
        }

        treeNode* p=new treeNode(n);
        if(root==NULL) {
            root=p;
            return;
            }

        else if(n>temp2->data){
            temp2->rightChild=p;
        }
        else temp2->leftChild=p;

    }

    treeNode* recInsertNode(treeNode* p, int n){

        if(p==NULL){
            return new treeNode(n);
        }

        if(n>p->data){
            p->rightChild=recInsertNode(p->rightChild,n);
        }

        if(n<p->data){
            p->leftChild=recInsertNode(p->leftChild,n);
        }

        return p;

    }

    void preorder(){
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

    void inorder(){
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

void levelorder(){
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

    treeNode* Rinsert(treeNode* p, int n){
        treeNode* t;
        if(p==NULL){
            
            t=new treeNode(n);

        }


        if(n<p->data){
            p->leftChild=Rinsert(p->leftChild,n);
        }
        else if(n>p->data){
            p->rightChild=Rinsert(p->rightChild,n);
        }

        return p;
        

    }

    treeNode* findNode(int n){
        treeNode* p,*t;
        p=root;

        while(p!=NULL){
            t=p;
            if(p->data==n){
                return t;
            }
        if(n>p->data){
            p=p->rightChild;
        }
        else{
            p=p->leftChild;
        }
    }
    return NULL;
}

int height(treeNode* p){
    
    int x=0;int y=0;
    if(p==NULL){
        return 0;
    }
    x=height(p->leftChild);
    y=height(p->rightChild);
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

};

int main() {
    BST tree;

    // Inserting nodes using recInsertNode
    tree.root = tree.recInsertNode(tree.root, 50);
    tree.recInsertNode(tree.root, 30);
    tree.recInsertNode(tree.root, 20);
    tree.recInsertNode(tree.root, 40);
    tree.recInsertNode(tree.root, 70);
    tree.recInsertNode(tree.root, 60);
    tree.recInsertNode(tree.root, 80);

    // Traversals
    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Level order traversal: ";
    tree.levelorder();
    cout << endl;

    cout<<tree.height(tree.root);

    return 0;

}