// encoding to euc-kr
#include <stdio.h>
#include <stdlib.h>
#include "./gotoxy.c"
#include "./setcursortype.c"
#include <conio.h>
#include <stdbool.h> // include boolean

const int refreshRate = 50; // 주파수

int main()
{
    setcursortype(NOCURSOR);
    int x = 0, y = 0;
    int cnt = 1;
    char ch;
    gotoxy(x, y);
    printf("@");
    while (true)
    {
        ch = '\0';
        if (kbhit()) // 키보드가 입력 받을 때만
            ch = getch();

        gotoxy(x, y);
        printf(" ");
        switch (ch)
        {
        case 'w':
            if (y > 0)
                y--;
            break;
        case 's':
            if (y < 24)
                y++;
            break;
        case 'a':
            if (x > 0)
                x--;
            break;
        case 'd':
            if (x < 79)
                x++;
        }
        gotoxy(x, y);
        printf("@");

        gotoxy(0, 0);
        printf("%d", cnt);          // 1/50 초마다 1씩 증가
        if (cnt % refreshRate == 0) // 1초마다 1씩 증가
            printf("\n%d", cnt / refreshRate);

        Sleep(1000 / refreshRate); // 주기 = 1/주파수
        cnt++;
    }
    return 0;
}