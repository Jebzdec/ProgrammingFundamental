#include <iostream>
using namespace std;
struct student{
    char name[100];
    int level;
    int score;
}s[5];
int main(){
    FILE* fp;
    fp = fopen("profund08","w");
    for(int i=0;i<5;i++){
        printf("Name Level Score\n");
        scanf("%s %d %d",s[i].name,&s[i].level,&s[i].score);
        fprintf(fp,"%s %d %d\n",s[i].name,s[i].level,s[i].score);
    }
    fclose(fp);
    return 0;
}