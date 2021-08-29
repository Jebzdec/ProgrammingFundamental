#include<iostream>
#include<vector>
using namespace std;
vector<int> s;
int main(){
    string a,b;
    cin>>a;
    b=a.substr(a.find(',')+1);
    a=a.substr(0,a.find(','));
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