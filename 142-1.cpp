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
        for(auto u:p[i]){
            if(islower(u)) a=1;
            else if(isupper(u)) A=1;
            else if(u=='$' or u=='#' or u=='@') S=1;
            else if(isalnum(u)) N=1;
            else F=1;
        }
        if(F==0 and a+A+N+S==4 and p[i].size()>=6 and p[i].size()<=12)
            cout<<p[i]<<" ("<<name[i]<<")";
    }
}