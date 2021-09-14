#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    bool row[8]={},column[8]={};
    while(t--){
        int x,y;
        cin>>x>>y;
        row[x-1]=1;
        column[y-1]=1;
    }
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(row[i]==0 and column[j]==0) cnt+=1;
        }
    }cout<<cnt;
}