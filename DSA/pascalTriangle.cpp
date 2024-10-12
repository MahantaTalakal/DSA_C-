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

void pascals(int x){
   for(int i=0;i<=x;i++){
      for(int j=0;j<=i;j++){
         cout<<combination(i,j)<<" ";
      }
      cout<<endl;
   }
}

int main(){
   int n;
   cout<<"enter the index uptil which the pascals trangle is needed: ";
   cin>>n;

   pascals(n);
}