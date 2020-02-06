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
    int x = 40, y = 20, cnt = 1, n = 0;
    int emX[5] = {0, 10, 20, 30, 40},
        emY[5] = {-1, -50, -10, -25, -15},
        bulX[10] = {
            0,
        },
        bulY[10] = {
            0,
        };
    char ch;
    gotoxy(x, y);
    printf("@");
    while (true)
    {
        // User
        ch = '\0';
        if (kbhit()) // 키보드가 입력 받을 때만
        {
            ch = getch();
            gotoxy(x, y);
            printf(" ");

            switch (ch)
            {
            case 'a':
                if (n > 10)
                    n = 0;
                bulX[n] = x;
                bulY[n] = y - 1;
                n++;
                break;
            case UP:
                if (y > 0)
                    y--;
                break;
            case DOWN:
                if (y < 24)
                    y++;
                break;
            case LEFT:
                if (x > 0)
                    x--;
                break;
            case RIGHT:
                if (x < 79)
                    x++;
                break;
            }
            gotoxy(x, y);
            printf("@");
        }

        // Enemy
        if (cnt % 10 == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                gotoxy(emX[i], emY[i]);
                printf(" ");
                if (emY[i] > 24)
                    emY[i] = -1;
                else
                    emY[i]++;
                if (emY[i] >= 0)
                {
                    gotoxy(emX[i], emY[i]);
                    printf("$");
                }
            }
        }
        if (cnt % 5 == 0)
        {
            for (int i = 0; i < 10; i++)
            {
                gotoxy(bulX[i], bulY[i]);
                printf(" ");
                if (bulY[i] <= 0)
                    bulY[i] = -1;
                else
                    bulY[i]--;

                if (bulY[i] >= 0)
                {
                    gotoxy(bulX[i], bulY[i]);
                    printf("!");
                }
            }
        }

        Sleep(1000 / refreshRate);
        cnt++;
        // 시분할 Time Sharing example
        // gotoxy(0, 0);
        // printf("%d", cnt);          // 1/50 초마다 1씩 증가
        // if (cnt % refreshRate == 0) // 1초마다 1씩 증가
        //     printf("\n%d", cnt / refreshRate);

        // Sleep(1000 / refreshRate); // 주기 = 1/주파수
        // cnt++;
    }
    return 0;
}