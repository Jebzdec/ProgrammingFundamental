#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
#define pv pair<pii,vector<int>>
#define f first
#define s second
using namespace std;
int main(){
    int a[100];
    for(int i=0;i<100;i++) a[i]=i;
    queue<vector<int>> q;
    vector<int> v,u;
    for(int i=0;i<100;i++)
    v.push_back(i);
    q.push(v.push_back(1));
    while(!q.empty()){
        u=q.front();
        for(auto i:u) cout<<i<<endl;
        q.pop();
    }
}

