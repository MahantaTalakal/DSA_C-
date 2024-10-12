#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    cout<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.capacity()<<endl;v.push_back(1);
    cout<<v.capacity()<<endl;v.push_back(1);
    cout<<v.capacity()<<endl;v.push_back(1);
    cout<<v.capacity()<<endl;
    cout<<sizeof(v)<<endl;
    cout<<sizeof(int*);
    


}