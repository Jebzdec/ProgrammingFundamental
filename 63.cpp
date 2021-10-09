#include<iostream>
using namespace std;
int main(){
    FILE *fr,*fw;
    fr=fopen("c:\\temp\\data1.txt","r");
    fw=fopen("c:\\temp\\data2.txt","w");
    char c;
    while((c=fgetc(fr))!=EOF){
        fputc(c,fw);
    }
    fclose(fr);
    fclose(fw);
}