// encoding to euc-kr
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD CursorPosition = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}