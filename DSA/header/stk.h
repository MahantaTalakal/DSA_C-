#include<iostream>
#include<stdlib.h>
#include"queue_arr.h"

using namespace std;

typedef struct Stack{
int size;
int top;
treeNode** arr;
}Stack;

void createStack(Stack *stack, int n){
    stack->size=n;
    stack->arr=(treeNode**)malloc(sizeof(treeNode*)*stack->size);
    stack->top=-1;
}

void PushStack(Stack* stack, treeNode* n){
    if(stack->top==stack->size-1){
        return;
    }
    stack->top++;
    stack->arr[stack->top]=n;
   
}

int stkIsEmpty(Stack* stack){
    return (stack->top==-1);
}

treeNode* PopStack(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    treeNode* x = stack->arr[stack->top];
    stack->top--;
    return x;
}