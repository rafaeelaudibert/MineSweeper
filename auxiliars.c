#include "mapa.h"
#include "auxiliars.h"

///Puts the ConsoleCursor in a given x,y position
void gotoXY(int x, int y)
{
    //Limit: Has limit equal to x-1, y-1 as of the values passed on system(mode x,y)
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

///Selects cursor appearance.
void cursorType(int cursor)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    switch(cursor)
    {
    case 0: //Turns off the cursor
        cursorInfo.dwSize = 100;
        cursorInfo.bVisible = FALSE;
        break;
    case 1: //Solid block cursor
        cursorInfo.dwSize = 100;
        cursorInfo.bVisible = TRUE;
        break;
    case 2:
        cursorInfo.dwSize = 10; //Normal underscore cursor
        cursorInfo.bVisible = TRUE;
        break;
    default:
        cursorType(2);
        return;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
