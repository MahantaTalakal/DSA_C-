#include<iostream>
#include<stdlib.h>

using namespace std;

class stack_arr{
    int capacity;
    int *arr;
    int top;

    public:

    stack_arr(int c){
        this->capacity=c;
        this->arr= (int*)malloc(sizeof(int)*capacity);
        this->top=-1;
    }

    void push(int n){
        if(top == capacity-1){
            cout<<"stack overflow"<<endl;
            return;
        }

        top++;
        this->arr[top]=n;
    }

    void pop(){
        if(top ==-1){
            cout<<"underflow"<<endl;
            return;
        }

        top--;
    }

    int get_top(){
        if(top ==-1) cout<<"underflow"<<endl;
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==this->capacity-1;
    }

    int size(){
        return top +1;
    }
};

int main(){

    stack_arr Stack(10);
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.push(40);
    cout<<Stack.get_top()<<endl;;
    Stack.pop();
    cout<<Stack.get_top()<<endl;
    Stack.push(89);
    cout<<Stack.get_top()<<endl;
}