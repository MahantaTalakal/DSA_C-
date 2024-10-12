#include<iostream>
using namespace std;

int mini(int x,int y){
   if(x>=y) return y;
   else return x;
}

int HCF(int x,int y){
   int minimum=mini(x,y);

   for (int i=minimum;i>1;i--){
      if(x%i==0 && y%i==0){
         return i;
      } 
   }
}

int main(){
   int x,y;
   cout<<"enter two numbers: "<<endl;
   cin>>x>>y;
   cout<<HCF(x,y);

}