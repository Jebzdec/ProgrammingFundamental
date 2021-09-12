#include <iostream>
#include <vector>
using namespace std;
int main(){
    string a;
    vector<char> v[100];
    cin>>a;
    int f=1,r=0,n;
    cin>>n;
    for(int i=0;i<a.size();i++){
        v[r].push_back(a[i]);
        if(r==0 or r==n-1) f=!f; 
        f==0? r++:r--;
    }
    for(int i=0;i<n;i++){
        for(auto j:v[i])
            cout<<j;
    }
}
