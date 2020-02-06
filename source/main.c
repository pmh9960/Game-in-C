// encoding to euc-kr
#include <stdio.h>
#include <stdlib.h>
#include "./gotoxy.c"
#include "./setcursortype.c"
#include <conio.h>
#include <stdbool.h> // include boolean

int main()
{
    setcursortype(NOCURSOR); // Ŀ�� �����̴� �� ����
    system("pause > nul");   // ����â �ٷ� ���� �ذ��

    int x = 0, y = 0;
    char ch;
    gotoxy(x, y);
    printf("@");
    while (true)
    {
        ch = getch(); // �Էµ� Ű�� ������ ����
        gotoxy(x, y);
        printf(" "); // @ �����
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