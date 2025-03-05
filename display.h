//
// Created by flasque on 05/03/2025.
//

#ifndef LANGTON_DISPLAY_H
#define LANGTON_DISPLAY_H

// use conio or ncurses depending on the OS
#if defined(_WIN32) || defined(_WIN64)
#include "conio.h"
#else
#include <ncurses.h>
#endif

void init_display(void);
void close_display(void);
void putpixel(int x, int y, int color);

#endif //LANGTON_DISPLAY_H
