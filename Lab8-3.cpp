#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
              ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}
int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}
void fill_ship_to_buffer(int x,int y,int color)
{
    char ship[6]= {"<-0->"};
    int k=0;
    //for(int i=x-2; i<=x+2; i++)
    {
        consoleBuffer[x + screen_x * y].Char.AsciiChar = 'W';
        consoleBuffer[x + screen_x * y].Attributes = color;
    }
}
void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
void Clear()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
            consoleBuffer[x + screen_x * y].Attributes = 7;
        }
    }
}
void gotoxy(int x, int y)
{
COORD c = { x, y };
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
int main()
{
    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT &&
                        eventBuffer[i].Event.KeyEvent.bKeyDown == true )
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x43)
                    {
                        play = false;
                    }
                    //printf("press : %c\n", eventBuffer[i].Event.KeyEvent.uChar.AsciiChar);
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT)
                {
                    int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                            FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        printf("left click\n");
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                             RIGHTMOST_BUTTON_PRESSED)
                    {
                        printf("right click\n");
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
                    {
                        printf("mouse position : (%d,%d)\n",posx, posy);
                        if(posx<80 and posy<25)
                        {
                        Clear();
                        fill_ship_to_buffer(posx,posy,7);
                        fill_buffer_to_console();
                        }
                    }
                }
            }
            delete[] eventBuffer;
        }
        Sleep(100);
    }
    return 0;
}

