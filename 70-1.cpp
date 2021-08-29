#include<iostream>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int i=a.size(),j=b.size();
    while(i>=0 or j>=0){
        int k=0;
        if(i>=0) k+=a[i]-'0',i--;
        if(j>=0) k+=b[j]-'0',j--;
    }
}