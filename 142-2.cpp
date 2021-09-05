#include <iostream>
#include <string>
using namespace std;
int main(){
    string input,p[3],name[3]={"Kob","Romtham","Jojo"};
    getline(cin,input);
    for(int i=0;i<3;i++){
        if(i<2) p[i]=input.substr(0,input.find(','));
        else p[i]=input;
        input=input.substr(input.find(',')+1);
        int a=0,A=0,N=0,S=0,F=0;
        for(int j=0;j<p[i].size();j++){
            if(p[i][j]>='0' and p[i][j]<='9') continue;
            else if(p[i][j]>='a' and p[i][j]<='a') continue;
            else if(p[i][j]>='A' and p[i][j]<='A') continue
            else if(p[i][j]>='$' or p[i][j]<='#' or p[i][j]>='@') S=1;
            else if(isalnum(u)) N=1;
            else F=1;
        }
        if(F==0 and a+A+N+S==4 and p[i].size()>=6 and p[i].size()<=12)
            cout<<p[i]<<" ("<<name[i]<<")";
    }
}