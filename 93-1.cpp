#include<iostream>
using namespace std;
int main(){
    int n,ans=0,j;
    cin>>n;
    int a[n+2][n+2]={};
    for(int i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            int x;
            cin>>x;
            a[i][j]=x+max(a[i-1][j],a[i-1][j-1]);
            if(i==n) ans=max(a[i][j],ans);
        }
    }cout<<ans;
}
