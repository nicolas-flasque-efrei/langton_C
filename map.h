//
// Created by flasque on 04/03/2025.
//

#ifndef LANGTON_MAP_H
#define LANGTON_MAP_H

// enum type for 'White' and 'Black' cells
typedef enum e_color
{
     BK=0, WH=15
} t_color;

// 2D grid structure storing s and 1s
// this grid has a 'toric' topology ; left and right edges are connected, top and bottom edges are connected
typedef struct s_map
{
    int **data;
    int width;
    int height;
} t_map;

// prototypes of functions with doxygen style comments

/**
 * Initialize a map
 * @param int width
 * @param int height
 * @return : a pointer to the map
 */
t_map init_map(int width, int height);

/**
 * Free a map
 * @param t_map *map
 */
void free_map(t_map map);

/**
 * Print the map
 * @param t_map *map
 */
void print_map(t_map map);
void file_print_map(t_map map);
#endif //LANGTON_MAP_H
