#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 20
#define screen_x 80
#define screen_y 25
HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
COORD star[scount];
HANDLE rHnd;
DWORD fdwMode;
int play = 10;
int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x,y};
    DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}
void clear_buffer()
{
    for(int i=0; i<screen_x; i++)
    {
        for(int j=0; j<screen_y; j++)
        {
            consoleBuffer[i + screen_x * j].Char.AsciiChar = ' ';
            consoleBuffer[i + screen_x * j].Attributes = 7;
        }
    }
}
void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
void init_star()
{
    for(int i=0; i<scount; i++)
    {
        star[i]= {rand()%(screen_x-1),rand()%(screen_y-1)};
    }
}
void star_fall()
{
    int i;
    for (i = 0; i < scount; i++)
    {
        if (star[i].Y >= screen_y-1)
        {
            star[i] = { (rand() % screen_x),1 };
        }
        else
        {
            star[i] = { star[i].X,star[i].Y+1 };
        }
        if(cursor(star[i].X,star[i].Y)!=' '){
            play--;
            star[i] = { (rand() % screen_x),1 };
        }
    }
}

void fill_star_to_buffer()
{
    for(int i=0; i<scount; i++)
    {
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
        consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
    }
}
int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}
void fill_ship_to_buffer(int x,int y,int color)
{
    char ship[6]= {"<-0->"};
    int k=0;
    for(int i=x-2; i<=x+2; i++)
    {
        consoleBuffer[i + screen_x * y].Char.AsciiChar = ship[k++];
        consoleBuffer[i + screen_x * y].Attributes = color;
    }
}
int main()
{
    int ship_color=7;
    int x_ship=-1,y_ship=-1;
    srand(time(NULL));
    setConsole(screen_x, screen_y);
    init_star();
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    while (play>0)
    {
        clear_buffer();
        star_fall();
        fill_star_to_buffer();
        if(x_ship-2>=0 and x_ship+2<screen_x and y_ship<screen_y)
        {
            fill_ship_to_buffer(x_ship,y_ship,ship_color);
        }
        fill_buffer_to_console();
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true )
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x43)
                    {
                        ship_color=rand()%255;
                    }
                    else if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {
                        play=0;
                    }
                }
                if (eventBuffer[i].EventType == MOUSE_EVENT)
                {
                    if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
                    {
                        int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                        int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                        if(posx>=2 and posx<screen_x-2){
                            x_ship=posx;
                        }
                        if(posy<screen_y){
                            y_ship=posy;
                        }
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        ship_color=rand()%255;
                    }
                }
            }
            delete[] eventBuffer;
        }
        Sleep(100);
    }
    return 0;
}
