#include<iostream>
using namespace std;
void Swap(int *x,int *y){
     int z=*x;
     *x=*y;
     *y=z;
}
int main(){
    int a,b;
    cin>>a>>b;
    Swap(&a,&b);
    cout<<a<<" "<<b;
}
