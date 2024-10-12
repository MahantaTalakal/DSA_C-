#include<iostream>

using namespace std;
int count=0;

void TOH(int n,int a,int b,int c){

    if(n>0){
        TOH(n-1,a,c,b);
        count++;
        cout<<"from "<<a<<"to"<<c<<endl;
        TOH(n-1,b,a,c);
    }
} 

int main(){
    int n;
    cout<<"enter the number of disks: ";
    cin>>n;
    TOH(n,1,2,3);
    cout<<count;
}