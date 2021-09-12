#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[8][8]={};
    for(int k=0;k<n;k++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        for(int j=0;j<8;j++){
             b[x][j]=1;
             b[j][y]=1;
        }
        int i=x,j=y;
        while(i<8 and j<8)
            b[i++][j++]=1;
        i=x,j=y;
        while(i>=0 and j>=0)
            b[i--][j--]=1;
        i=x,j=y;
        while(i<8 and j>=0)
            b[i++][j--]=1;
        i=x,j=y;
        while(i>=0 and j<8)
            b[i--][j++]=1;
    }
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(b[i][j]==0) cnt++;
        }
    }cout<<cnt;
}
