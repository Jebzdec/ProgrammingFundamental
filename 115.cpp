#include<iostream>
using namespace std;
int visit[1000][1000]={};
int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n,m;
void dfs(int x,int y){
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        int X=x+d[i][0],Y=y+d[i][1];
        if(X>=0 and X<n and Y>=0 and Y<m and !visit[X][Y]){
            dfs(X,Y);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            visit[i][j]=a;
        }
    }
    dfs(0,0);
    visit[n-1][m-1]==0? cout<<"No":cout<<"Yes";
}
