#include<iostream>
#include<stdlib.h>


using namespace std;

struct rectangle{
    int length;
    int breadth;
    char ch[2];
};

int main(){
    rectangle r={10,5};
    cout<<sizeof(rectangle);

    int *ptr=(int*) malloc(5*sizeof(int));

    for(int i=0;i<5;i++){
        cout<<"inter the number "<<i;
        cin>>ptr[i];
    }

    for(int i=0;i<5;i++){
        cout<<ptr[i];
    }

    

}
