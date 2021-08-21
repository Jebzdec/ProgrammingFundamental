#include<iostream>
#include<cmath>

using namespace std;
int main(){
    float a=3.3,b=4.4,c=5.5;
    printf("%f %f %f %f\n",a*a,b*b,c*c,a*a+b*b-c*c);

    if(abs((a*a)+(b*b)-(c*c))<1e-6) cout<<"equal";
    else cout<<"no";
}
