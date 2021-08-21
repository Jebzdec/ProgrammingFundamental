#include<iostream>
using namespace std;
int a[1000][1000];
    int n,Max=0;
int dfs(int x,int y,int sum){
    if(x==1) Max=max(sum+a[x][y],Max);
    if(x<1 or y<1 or x>n or y>n) return 0;
    dfs(x-1,y-1,sum+a[x][y]);
    dfs(x-1,y,sum+a[x][y]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int j=1;j<=n;j++) dfs(n,j,0);
    cout<<Max;
}

