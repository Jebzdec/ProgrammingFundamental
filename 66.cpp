#include<iostream>
#include<string.h>
using namespace std;
int main(){
    FILE* fp;
    fp=fopen("c:\\temp\\data.txt ","w");
    char s[1000];
    printf("Input data string");
    while(strcmp(s,".")){
        scanf("%s",&s);
        fprintf(fp,"%s\n",s);
    }
    fclose(fp);
}