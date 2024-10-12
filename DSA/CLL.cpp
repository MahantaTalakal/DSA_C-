#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

typedef struct node{
    int data;
    node*next;
}node;

node* create_node(int n){
    node*p=(node*)malloc(sizeof(node));
    p->data=n;
    p->next=NULL;
    return p;
}

node* insert_front(node* head,int n){
    node*p=create_node(n);
    if(head==NULL){
        head=p;
        p->next=head;
        return head;
    }
    else{
        node*temp=head;
        while(temp->next!=head) temp=temp->next;
    
    p->next=head;
    temp->next=p;
    head=p;
    return head;
    }
}

node* insert_end(node* head,int n){

    if(head==NULL) return insert_front(head,n);

    else{
    node* ptr=head;

    while(ptr->next!=head){
        ptr=ptr->next;
    }
    node*p=create_node(n);
    ptr->next=p;
    p->next=head;
    return head;}
}

node* insert_index(node*head,int index,int n){
    if (index < 0) {
        cout << "Index cannot be negative." << endl;
        return head;
    }

    if((head==NULL && index==0)|| index==0){
        return insert_front(head,n);
    }

    else{
    node* temp=head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    node*p=create_node(n);
    p->next=temp->next;
    temp->next=p;
    return head;
    }
}

node*delete_first(node* head,int * deleted){
    if(head==NULL) {cout<<"the list is empty";
    return NULL;}

    else{
        node*ptr=head;
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }

        head=head->next;
        temp->next=head;
        *deleted=ptr->data;
        free(ptr);
        return head;
    }
}

node* pop(node*head, int *deleted){
    if(head==NULL) {cout<<"the list is empty";
    return NULL;}

    else if(head->next==NULL){
        node*ptr=head;
        head=NULL;
        *deleted=ptr->data;
        free(ptr);
        return head;
    }

    else{
        node*ptr=head;
        while((ptr->next)->next!=head){
            ptr=ptr->next;
        }
        *deleted=ptr->next->data;
        free((ptr->next));
        ptr->next=head;

        return head;
    }
}

node* delete_index(node*head,int index,int*deleted){
    if(head==NULL) {cout<<"the list is empty";
    return NULL;}

    else if (index == 0) {
        node* ptr = head;
        *deleted = ptr->data;
        head = head->next;
        delete ptr;
        return head;
    }

    else{
        node*ptr=head;
        for(int i=0;i<index-1;i++){
            ptr=ptr->next;
        }
        node*temp=ptr->next;
        ptr->next=(ptr->next)->next;

        *deleted=(ptr->next)->data;
        free(temp);
        return head;
    }
}

node* clear_list(node* head) {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
    } else {
        node* temp = head;
        node*current =head;

        do{
            current= current->next;
            free(temp);
            temp = current;
        }while(current!=head);
        
        head = NULL;
        free(temp);
    }

    return head;
}



void disp(node*head){

    if(head==NULL){
        cout<<"the list is empty.";
    }
    node*p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;}
        
        while(p!=head);
        cout<<endl;
}

int main(){
    node*head=NULL;

    int choice,n;
    int deleted;

do{
        cout<<"enter your choice: "<<endl;
        cout<<"1.insert front."<<endl;
        cout<<"2.insert end."<<endl;
        cout<<"3.insert at specific index."<<endl;
        cout<<"4.display list."<<endl;
        cout<<"5.delete front."<<endl;
        cout<<"6.pop"<<endl;
        cout<<"7.delete at index."<<endl;
        cout<<"8.reverse the linked list"<<endl;
        cout<<"9.empty the list."<<endl;

        cin>>choice;
        
        switch (choice)
    {
    case 1:
        cout<<"enter data: ";
        cin>>n;
        head=insert_front(head,n);
        break;
    
    case 2:
        cout<<"enter data: ";
        cin>>n;
        head=insert_end(head,n);
        break;

    case 3: 
        int index;
        cout<<"enter data: ";
        cin>>n;
        cout<<"enter index: ";
        cin>>index;
        
        head=insert_index(head,index,n);
        break;

    case 4:
        disp(head);
        break;

    case 5:
        
        head=delete_first(head,&deleted);
        cout<<deleted<<" is deleted from the list."<<endl;
        break;
    
    case 6:
        head=pop(head,&deleted);
        cout<<deleted<<" is deleted from the list."<<endl;
        break;
    case 7:
        cout<<"enter index:";
        cin>>index;
        head=delete_index(head,index,&deleted);
        cout<<deleted<<" is deleted from the list."<<endl;
        break;
    

    /*case 8:
        cout<<"reverse the linked list"<<endl;
        head=reverse(head);
        disp(head);*/
    
    case 9:
        head=clear_list(head);

    }}while(choice<10);

    clear_list(head);
}