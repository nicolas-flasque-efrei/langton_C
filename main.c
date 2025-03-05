#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "loc.h"
#include "display.h"


#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define pause(x) Sleep(x)
#else
#include <unistd.h>
#define pause(x) usleep(1000.0*x)
#endif

int main() {
    init_display();
    // create a 30x30 map
    t_map map = init_map(100, 100);
    // initialize the location of the ant
    t_coord loc = init_loc(35, 35, E);
    // print the map
    int iter_max = 15000;
    for (int i = 0; i < iter_max; i++) {
        // make a pause of 500 microsecs
        //pause(1);
        if (get_map_value(loc, map) == WHITE) {
            loc = turn_right(loc);
        }
        else if (get_map_value(loc, map) == BLACK) {
            loc = turn_left(loc);
        }
        change_map_value(loc, map);
        putpixel(loc.x, loc.y, get_map_value(loc,map));
        loc = forward(loc, map);
    }
    scanf("%s",&iter_max);
    close_display();
    return 0;
}
