#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m[8][8]={};
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        for(int j=0;j<8;j++){
            m[a][j]=1;
            m[j][b]=1;
        }
    }
    int k=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(m[i][j]==0) k++;
        }
    }cout<<k;
}