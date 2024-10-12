#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    int *p=(int*)malloc(5*(sizeof(int)));

    cout<<"enter the values of array: ";
    for(int i=0;i<5;i++){
        cin>>p[i];
    }

    for(int i=0;i<5;i++){
        cout<<p[i]<<" ";
    }

    cout<<endl;
    cout<<p;

    free(p);
}