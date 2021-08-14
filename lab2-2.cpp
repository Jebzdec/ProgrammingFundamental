#include<iostream>
using namespace std;
int main(){
    int a,b,k;
    cout<<"Enter first number : ";
    cin>>a;
    cout<<"Enter second number : ";
    cin>>b;
    cout<<"Greatest common divisor = ";
    if(b>a) swap(a,b);
    if(a==0) cout<<b;
    else if(b==0) cout<<a;
    else while(true){
        k=a%b;
        if(k==0){cout<<b;break;}
        a=b;
        b=k;
    }
}
