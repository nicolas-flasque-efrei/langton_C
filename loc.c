//
// Created by flasque on 04/03/2025.
//

#include "loc.h"

t_coord init_loc(int x, int y, t_orientation orientation) {
    t_coord loc = {x, y, orientation};
    return loc;
}

t_coord UP(t_coord loc, t_map map)
{
    t_coord new_loc = loc;
    new_loc.y = (loc.y - 1);
    if (new_loc.y < 0) {
        new_loc.y = map.height - 1;
    }
    return new_loc;
}

t_coord DOWN(t_coord loc, t_map map)
{
    t_coord new_loc = loc;
    new_loc.y = (loc.y + 1) % map.height;
    return new_loc;
}

t_coord LEFT(t_coord loc, t_map map)
{
    t_coord new_loc = loc;
    new_loc.x = (loc.x - 1);
    if (new_loc.x < 0) {
        new_loc.x = map.width - 1;
    }
    return new_loc;
}

t_coord RIGHT(t_coord loc, t_map map)
{
    t_coord new_loc = loc;
    new_loc.x = (loc.x + 1) % map.width;
    return new_loc;
}

t_coord forward(t_coord loc, t_map map) {
    t_orientation ori = loc.orientation;
    switch (ori) {
        case N:
            return UP(loc, map);
        case S:
            return DOWN(loc, map);
        case E:
            return RIGHT(loc, map);
        case W:
            return LEFT(loc, map);
    }
}

t_coord turn_left(t_coord loc)
{
    t_coord new_loc = loc;
    switch (loc.orientation) {
        case N:
            new_loc.orientation = W;
            break;
        case S:
            new_loc.orientation = E;
            break;
        case E:
            new_loc.orientation = N;
            break;
        case W:
            new_loc.orientation = S;
            break;
    }
    return new_loc;

}

t_coord turn_right(t_coord loc) {
    t_coord new_loc = loc;
    switch (loc.orientation) {
        case N:
            new_loc.orientation = E;
            break;
        case S:
            new_loc.orientation = W;
            break;
        case E:
            new_loc.orientation = S;
            break;
        case W:
            new_loc.orientation = N;
            break;
    }
    return new_loc;
}

t_color get_map_value(t_coord loc, t_map map) {
    return map.data[loc.y][loc.x];
}

void change_map_value(t_coord loc, t_map map) {
    t_color value = WH;

    if (map.data[loc.y][loc.x] == WH)
    {
        value = BK;
    }

    map.data[loc.y][loc.x] = value;
}