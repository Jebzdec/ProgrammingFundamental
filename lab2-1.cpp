#include<iostream>
using namespace std;
int main(){
    int n;
    printf("Enter number : ");
    cin>>n;
    cout<<"Factoring Result : ";
    for(int i=2;i<=n;i++){
        while(n%i==0){
            cout<<i;
            n=n/i;
            if(n>1)cout<<" x ";
        }
    }
}

