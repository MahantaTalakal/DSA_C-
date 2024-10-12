#include <iostream>
#include <stdlib.h>

using namespace std;

struct array {
    int arr[20];
    int size = 20;
    int length = 0;
};

void disp(struct array arrs) {
    for (int i = 0; i < arrs.length; i++) {
        cout << arrs.arr[i] << " ";
    }
    cout << endl;
}

void add(struct array *arrs, int n) {
    if (arrs->length < arrs->size) {
        arrs->arr[arrs->length] = n;
        arrs->length++;
    } else {
        cout << "Array is full. Cannot add more elements." << endl;
    }
}

void insert(struct array *arrs, int index, int n) {
    if (index <= arrs->length && arrs->length < arrs->size) {
        for (int i = arrs->length - 1; i >= index; i--) {
            arrs->arr[i + 1] = arrs->arr[i];
        }
        arrs->length++;
        arrs->arr[index] = n;
    } else {
        if (arrs->length >= arrs->size) {
            cout << "Array is full. Cannot add more elements." << endl;
        } else {
            cout << "Index out of bounds." << endl;
        }
    }
}

void pop(struct array *arrs) {
    if (arrs->length > 0) {
        arrs->length--;
    } else {
        cout << "Array is empty. Cannot pop elements." << endl;
    }
}

void remove(struct array *arrs, int index) {
    if (index < arrs->length && index >= 0) {
        for (int i = index; i < arrs->length - 1; i++) {
            arrs->arr[i] = arrs->arr[i + 1];
        }
        arrs->length--;
    } else {
        cout << "Index out of bounds." << endl;
    }
}

int linear_search(struct array *arrs,int n){
    int flag=0;
    for(int i=0;i<arrs->length;i++){
        if(arrs->arr[i]==n) {
            int temp;
            arrs->arr[i]= temp;
            arrs->arr[i]=arrs->arr[i-1];
            arrs->arr[i-1]=temp;
            return i;}
    }

    return flag;
}

int main() {
    struct array arrs;

    cout << "Enter the number of elements: ";
    cin >> arrs.length;

    if (arrs.length > arrs.size) {
        cout << "Number of elements exceeds the maximum size of the array." << endl;
        return 1;
    }

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < arrs.length; i++) {
        cout << i << ':';
        cin >> arrs.arr[i];
    }

    disp(arrs);

    add(&arrs, 6);
    disp(arrs);

    insert(&arrs, 3, 2);
    disp(arrs);

    pop(&arrs);
    disp(arrs);

    remove(&arrs, 3);
    disp(arrs);

    cout<<linear_search(&arrs,2);

    return 0;
}
