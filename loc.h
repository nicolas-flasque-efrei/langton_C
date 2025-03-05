//
// Created by flasque on 04/03/2025.
//

#ifndef LANGTON_LOC_H
#define LANGTON_LOC_H

#include "map.h"
// define a structure to represent the location of the langton ant on the grid
// using coordinates and orientation from N, S, E, W

// create an enum to represent the orientation of the ant
typedef enum e_orientation
{
    N, S, E, W
} t_orientation;

// create a struct to represent the location of the ant
typedef struct s_loc
{
    int x;
    int y;
    t_orientation orientation;
} t_coord;

// prototypes of functions with doxygen style comments

/** @brief Initialize a location
 *
 * @param x
 * @param y
 * @param orientation
 * @return t_coord
 */
t_coord init_loc(int x, int y, t_orientation orientation);

/** @brief moves the ant in some direction, and returns the new location wrt the map
 *
 * @param loc
 * @param map
 * @return
 */
t_coord UP(t_coord loc, t_map map);
t_coord DOWN(t_coord loc, t_map map);
t_coord RIGHT(t_coord loc, t_map map);
t_coord LEFT(t_coord loc, t_map map);
t_coord turn_left(t_coord loc);
t_coord turn_right(t_coord loc);

t_coord forward(t_coord loc, t_map map);

t_color get_map_value(t_coord loc, t_map map);
void change_map_value(t_coord loc, t_map map);

#endif //LANGTON_LOC_H
