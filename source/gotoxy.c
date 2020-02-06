// encoding to euc-kr
#include <stdio.h>
#include <windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void gotoxy(int x, int y)
{
    COORD CursorPosition = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}