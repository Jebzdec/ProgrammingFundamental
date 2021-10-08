#include<iostream>
#include<queue>
using namespace std;
int visit[1000][1000]={};
int d[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n,m;
int main(){
    cin>>n>>m;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            visit[i][j]=a;
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int u=q.front().first,
            v=q.front().second;
        q.pop();
        visit[u][v]=1;
        for(int i=0;i<4;i++){
            int x=u+d[i][0],
                y=v+d[i][1];
            if(x>=0 and x<n and y>=0 and y<m and !visit[x][y]){
                q.push({x,y});
            }
        }
    }
    visit[n-1][m-1]==0? cout<<"No":cout<<"Yes";
}
