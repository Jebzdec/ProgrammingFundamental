#include <iostream>
#include <windows.h>
#include <conio.h>
#include <queue>
using namespace std;
void draw_ship(int,int);
void Erase(int,int);
void setcursor(bool);
void setcolor(int,int);
void draw_P(int,int);
char ch=' ';
queue<pair<int,int>> q;
int main(){
    int x=30,y=25;
    setcursor(0);
    draw_ship(x,y);
    int d=0,cnt=0;
    do {
        setcursor(0);
        if (_kbhit()){
            ch=_getch();
            if(ch=='a') d=0;
            else if(ch=='d') d=1;
            else if(ch=='s') d=-1;
            else if(ch==' ' and cnt<5){
                q.push({x,y-1});
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            if(!q.empty()){
            int X=q.front().first,
                Y=q.front().second;
            q.pop();
            Erase(X,Y+1);
            if(Y-1>=0) draw_P(X,Y);
            if(Y>=0) q.push({X,Y-1});
            else cnt--;
            }
        }
        if(d==0 and x>=0){
            if(x>0){
                Erase(x,y);
                draw_ship(--x,y);
            }
            else draw_ship(x,y);
        }
        else if(d==1 and x<80){
            if(x<79){
                Erase(x,y);
                draw_ship(++x,y);
            }
            else draw_ship(x,y);
        }
        else if(d==-1)
            draw_ship(x,y);
        fflush(stdin);
        Sleep(300);
    } while (ch!='x');
    return 0;
}
void setcolor(int fg,int bg){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void Erase(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
    setcursor(0);
    setcolor(2,0);
    for(int i=0;i<80;i++)
        cout<<" ";
}
void draw_P(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
    setcursor(0);
    cout<<"  O  ";
}
void draw_ship(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
    setcursor(0);
    setcolor(2,4);
    cout<<"<-0->";
}


