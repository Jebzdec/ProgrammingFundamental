#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n){
    if(n<2) return 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 1;
    }return 0;
}
int main(){
    int x;
    cin>>x;
    isPrime(x)==0? cout<<"Prime Number":cout<<"Not Prime Number";
}