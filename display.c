//
// Created by flasque on 05/03/2025.
//

#include <stdio.h>
#include <windows.h>
#include "display.h"

// check for OS
#if defined(_WIN32) || defined(_WIN64)
#define FONT_SIZE 5
void init_display()
{
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the current font information
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Set the new font size
    fontInfo.dwFontSize.Y = FONT_SIZE;
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void putpixel(int x, int y, int color)
{
    c_gotoxy(x,y);
    c_textcolor(color);
    printf("%c", 219);
}

void close_display() {}

#else
void init_display() { initscr(); resize_term(100, 100); start_color(); init_pair(1, COLOR_WHITE, COLOR_BLACK); init_pair(2, COLOR_BLACK, COLOR_BLACK);}

void putpixel(int x, int y, int color)
{
    int pairnum = 0;
    if (color == WH)
    {
        pairnum = 1;
    }
    move(y, x);
    attron(COLOR_PAIR(pairnum))
    printw("%c", 219);
    attroff(COLOR_PAIR(pairnum));
    refresh();
}

void close_display() { endwin(); }
#endif