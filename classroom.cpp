#include<iostream>
using namespace std;
int main(){
    char s[100],*p,f={};
    cin>>s;
    p=s;
    while(*p!='\0'){
        if(f!=*p) cout<<*p;
        f=*p;
        p++;
    }
}