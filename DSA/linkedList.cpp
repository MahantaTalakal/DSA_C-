#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node* next;
} node;

// Function to create a new node
node* create_node(int n) {
    node* p = new node; // Allocate memory using new
    p->data = n;
    p->next = NULL;
    return p;
}

// Function to display the linked list
void disp(node* p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int count_list(node* temp) {
    int count=0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sum(node* head){
    int sum=0;
    while(head!=NULL){
        sum+=head->data;
        head=head->next;
    }

    return sum;
}

int max(node* head){
    int max=INT32_MIN;
    while(head!=NULL){
        if(max<head->data) max=head->data;

        head=head->next;
    }
    return max;
}

int Rmax(node*head){
    static int max=INT32_MIN;
    if(head=NULL) return max;

    else{
        max=Rmax(head->next);
        if(max>head->data) return max;
        else return head->data;
    }
    }

int search(node*head,int n){
    int count =0;
    while(head!=NULL){
        if(n==head->data) break;
        else head=head->next;
        count++;
        
    }

    return count; 
}

int main() {
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;

    node* head = NULL;
    node* last = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        cin >> data;
        if (head == NULL) {
            head = create_node(data);
            last = head;
        } else {
            node* p = create_node(data);
            last->next = p;
            last = p;
        }
    }

    cout << "Displaying the linked list:" << endl;
    disp(head);

    
    return 0;
}
