#include<iostream>

using namespace std;

int main(){
    int a=10;
    int &r=a;
    int b=11;
    r=b;
    r=20;


    cout<<"b: "<<&b<<endl;
    cout<<"r: "<<&r<<endl;
    cout<<"a: "<<&a<<endl;
    cout<<"r: "<<r<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}