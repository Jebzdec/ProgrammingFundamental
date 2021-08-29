#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> a,b,s;
int main(){
    string x;
    cin>>x;
    bool func=0;
    for(int i=0;i<x.size();i++){
        if(x[i]==','){ func=1;continue;}
        func==0? a.push_back(x[i]):b.push_back(x[i]);
    }
    if(a.size()<b.size()) swap(a,b);
    int i=a.size()-1,j=b.size()-1,k,t=0;
    while(i>=0 or j>=0){
        k=t;
        if(i>=0) k+=int(a[i]-'0'),i--;
        if(j>=0) k+=int(b[j]-'0'),j--;
        t=k/10;
        k=k%10;
        s.push_back(k);
    }
    for(int i=s.size()-1;i>=0;i--) cout<<s[i]; 
}