#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void draw_ship(int,int);
void erase_ship(int,int);
void setcursor(bool);
char ch=' ';
int main(){
    int x=20,y=20;
    setcursor(0);
    draw_ship(x,y);
    do {
        setcursor(0);
        if (_kbhit()){
        ch=_getch();
        if(ch=='a' and x-1>=0) {
            erase_ship(x,y);
            draw_ship(--x,y);
        }
        if(ch=='d' and x+1<80) {
            erase_ship(x,y);
            draw_ship(++x,y);
        }
        if(ch=='w' and y-1>=0) {
            erase_ship(x,y);
            draw_ship(x,--y);
        }
        if(ch=='s' and y+1<25) {
            erase_ship(x,y);
            draw_ship(x,++y);
        }
        fflush(stdin);
        }
        Sleep(100);
    } while (ch!='x');
    return 0;
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void erase_ship(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
    setcursor(0);
    for(int i=0;i<80;i++){
        cout<<" ";
    }
}
void draw_ship(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
    setcursor(0);
    cout<<"<-0->";
}

