// encoding to euc-kr
#include <stdio.h>
#include <stdlib.h>
#include "./gotoxy.c"
#include "./setcursortype.c"
#include <conio.h>
#include <stdbool.h> // include boolean

int main()
{
    setcursortype(NOCURSOR); // 커서 깜박이는 것 조절
    system("pause > nul");   // 실행창 바로 닫힘 해결법

    int x = 0, y = 0;
    char ch;
    gotoxy(x, y);
    printf("@");
    while (true)
    {
        ch = getch(); // 입력된 키를 변수에 대입
        gotoxy(x, y);
        printf(" "); // @ 지우기
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
    }

    return 0;
}