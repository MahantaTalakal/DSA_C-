#include<iostream>

using namespace std;



int sumN(int n){
 
    if(n>1){
        return(sumN(n-1)+n);
    }

    else return 1;
}

int main(){
    int x;
    cin>>x;
    cout<<sumN(x);
}