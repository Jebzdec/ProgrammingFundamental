#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
void gotoxy(int,int);
void draw_ship(int,int);
void draw_bullet(int,int);
void clear_bullet(int,int);
void setcursor(bool);
void draw_star();
char cursor(int,int);
void score(int);
void sound();
int main(){
    char ch='.';
    int x=38,y=20;
    int bx,by,i;
    int bullet,cnt=0;
    srand(time(NULL));
    for(int i=0;i<20;i++) draw_star();
    draw_ship(x,y);
    score(cnt);
    do {
        if (_kbhit()){
            ch=_getch();
            if(ch=='a' and x-1>=0) draw_ship(--x,y);
            if(ch=='s' and x+1<80) draw_ship(++x,y);
            if(bullet!=1 && ch==' ') {
                bullet=1;
                bx=x+3;
                by=y-1;
            }
            fflush(stdin);
        }
        if (bullet==1){
            clear_bullet(bx,by);
            if(by==2){
                bullet=0;
            }
            else{
                if(cursor(bx,by-1)=='*'){
                    clear_bullet(bx,by-1);//clear star *
                    bullet=0;
                    score(++cnt);
                    draw_star();
                    sound();
                }
                else draw_bullet(bx,--by);
            }
        }
        Sleep(100);
        } while (ch!='x');
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    setcursor(0);
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y); printf(" <-0-> ");
}
void draw_bullet(int x,int y)
{
    gotoxy(x,y); printf("o");
}
void clear_bullet(int x,int y)
{
    gotoxy(x,y); printf(" ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void draw_star(){
    int x,y;
    do{
        x=rand()%61+10;
        y=rand()%4+2;
    }while(cursor(x,y)=='*');
    gotoxy(x,y);
    printf("*");
}
char cursor(int x, int y){
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x,y};
    DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}
void score(int sc){
    gotoxy(80,0);
    printf("score : %d",sc);
}
void sound(){
    Beep(800,100);
    Beep(750,100);
    Beep(900,100);
}
