#include<iostream>
using namespace std;

int factorial(int x){
   int r=1;
   for(int i=1;i<=x;i++){
      r*=i;
   }
   return r;
}

int combination(int x,int y){
   int r_f=factorial(x);
   int n_f=factorial(y);
   int NR_f=factorial(x-y);

   return r_f/(n_f*NR_f);

}

int permuatation(int x, int y){
   int r_f=factorial(x);
   int NR_f=factorial(x-y);

   return r_f/NR_f;

}
int main(){
   int n,r;
   cout<<"enter the value of n and r: ";
   cin>>n>>r;

   cout<<"nCr: "<<combination(n,r);
}