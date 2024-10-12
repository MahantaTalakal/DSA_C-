#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct stack_arr
{
    int size;
    int top;
    int *arr;
} stack_arr;

void create_stack(stack_arr *stack, int n){
    stack->size = n;
    stack->arr = (int*)malloc(sizeof(int) * n);
    stack->top = -1;
}

void push(stack_arr *stack, int n){
    if(stack->top == stack->size - 1){
        cout << "overflow" << endl;
        return;
    }

    stack->top++;
    stack->arr[stack->top] = n;
}

void pop(stack_arr *stack){
    if(stack->top == -1){
        cout << "underflow" << endl;
        return;
    }
    cout << stack->arr[stack->top] << " is removed from the stack." << endl;
    stack->top--;
}

int isEmpty(stack_arr *stack){
    return (stack->top == -1);
}

int isFull(stack_arr *stack){
    return (stack->top == stack->size - 1);
}

int peek(stack_arr *stack){
    if(stack->top == -1){
        cout << "Stack is empty." << endl;
        return -1; // Return a sentinel value indicating the stack is empty
    }
    return stack->arr[stack->top];
}

int stackSize(stack_arr *stack){
    return stack->top + 1;
}

void display_stack(stack_arr *stack){
    if(stack->top == -1){
        cout << "Stack is empty." << endl;
        return;
    }
    for(int i = stack->top; i>=0; i--){
        cout << stack->arr[i] << endl;
    }
    cout << endl;
}

int main(){
    stack_arr stack;
    int max_size;
    cout << "Enter max size of the stack: ";
    cin >> max_size;
    create_stack(&stack, max_size);

    int choice, n;

    do{
        cout << "Enter your choice: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if stack is empty" << endl;
        cout << "4. Check if stack is full" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Size of stack" << endl;
        cout << "7. Display stack" << endl;
        cout << "8. Exit" << endl;

        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> n;
                push(&stack, n);
                break;
            
            case 2:
                pop(&stack);
                break;

            case 3:
                if(isEmpty(&stack))
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 4:
                if(isFull(&stack))
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;

            case 5:
                n = peek(&stack);
                if(n != -1)
                    cout << "Top element is: " << n << endl;
                break;

            case 6:
                cout << "Size of stack is: " << stackSize(&stack) << endl;
                break;

            case 7:
                display_stack(&stack);
                break;

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(choice != 8);

    free(stack.arr);
    return 0;
}
