#include "movement.h"
#include "mapa.h"

char detectKey()
{
    char key='x';

    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57)) //Up key
    {
        key = 'w';
    }
    else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53)) //Down key
    {
        key = 's';
    }
    else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) //Left key
    {
        key = 'a';
    }
    else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)) //Right key
    {
        key = 'd';
    }
    else if (GetAsyncKeyState(VK_SPACE)) //'Esc' or 'Space' key
    {
        key = ' ';
    }
    else if (GetAsyncKeyState(VK_RETURN))
    {
        key = 'e';
    }

    return key;

}
