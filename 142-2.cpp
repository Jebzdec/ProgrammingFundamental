#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string input;
    vector<char> p[3];
    getline(cin,input);
    int k=0;
    for(int i=0;i<input.size();i++){
        if(input[i]==','){
            k++;
            continue;
        }p[k].push_back(input[i]);
    }
     for(int i=0;i<3;i++){
         if(p[i].size()<6 or p[i].size()>12) continue;
         int a=0,A=0,num=0,S=0;
         for(int j=0;j<p[i].size();j++){
             if(p[i][j]>='0' and p[i][j]<='9') num++;
             else if(p[i][j]>='a' and p[i][j]<='z') a++;
             else if(p[i][j]>='A' and p[i][j]<='Z') A++;
             else if(p[i][j]=='$' or p[i][j]=='#' or p[i][j]=='@') S++;
             else break;
             if(j==p[i].size()-1 and num>0 and a>0 and A>0 and S>0){
                 for(auto a:p[i]) cout<<a;
                 if(i==0) printf(" (Kob)");
                 else if(i==1) printf(" (Romtham)");
                 else if(i==2) printf(" (Jojo)");
             }
         }
     }
}
