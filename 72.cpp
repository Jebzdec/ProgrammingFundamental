#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
#define pv pair<pii,vector<int>>
#define f first
#define s second
using namespace std;
int main(){
    int n,start;
    printf("Enter no. of vertices:");
    cin>>n;cout<<endl<<"Enter the adjacency matrix:\n";
    vector<pii> node[n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>> x;
            if(i!=j and x!=0) node[i].push_back({x,j});
        }
    }
    cout<<endl<<"Enter the starting node:";
    cin>>start;
    for(int i=0;i<n;i++){
        if(i==start) continue;
        printf("\nDistance of node%d=",i);
        bool visit[1000]={};
        priority_queue<pv,vector<pv>,greater<pv>> q;
        vector<int> path;
        q.push({{0,start},path});
        int u=start,w;
        while(u!=i){
            w=q.top().f.f,
            u=q.top().f.s,
            path=q.top().s;
            q.pop();
            path.push_back(u);
            visit[u]=1;
            for(auto v:node[u]){
                if(visit[v.s]==0) q.push({{v.f+w,v.s},path});
            }
        }cout<<w<<endl<<"Path=";
        for(auto j=path.end()-1;j>=path.begin();j--){
            cout<<*j;
            if(j>path.begin()) cout<<"<-";
        }
    }cout<<"\n--------------------------------";
}
