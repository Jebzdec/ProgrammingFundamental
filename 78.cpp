#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    int a[n+1]={},b[n+1]={},c=0,d=0,num[10000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            num[x]=1;
            a[i]+=x;
            b[j]+=x;
            if(i==j) c+=x;
            else if(n-1-i==j) d+=x;
        }
    }
    for(int i=1;i<=n*n;i++){
        if(num[i]==0){
            cout<<"No";
            goto End;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i] and b[i]==c and c==d) continue;
        else{
            cout<<"No";
            goto End;
        }
    }cout<<"Yes";
    End:;
}
