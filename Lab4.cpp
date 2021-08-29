#include<iostream>
#include<string>
using namespace std;
int main(){
    string st;
    cin>>str;
    int l=-1;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0' and str[i]<='9'){
            if(l>0) l=l*10+str[i]-'0';
            else l=str[i]-'0';
        }
        else{
            if(l==-1) cout<<str[i];
            else{
            for(int j=0;j<l;j++)
                cout<<str[i];
            l=-1;
            }
        }
    }
}
