#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>v;
    int n;
    cout<<"enter the number of elements in vector: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cout<<"enter the element: ";
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int size=v.size();
    int temp;

    for(int i=0; i<v.size()/2;i++){
        temp=v[i];
        v[i]=v[size-i-1];
        v[size-i-1]=temp;

    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
}