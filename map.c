//
// Created by flasque on 04/03/2025.
//

#include <malloc.h>
#include <stdio.h>
#include "map.h"

static char _disp[]=" X";

t_map init_map(int width, int height)
{
    t_map map;
    map.width = width;
    map.height = height;
    map.data = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        map.data[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            map.data[i][j] = BK;
        }
    }
    return map;
}

void free_map(t_map map)
{
    for (int i = 0; i < map.height; i++) {
        free(map.data[i]);
    }
    free(map.data);
}

void print_map(t_map map)
{
    for (int i = 0; i < map.height; i++) {
        for (int j = 0; j < map.width; j++) {
            printf("%c", _disp[map.data[i][j]]);
        }
        printf("\n");
    }
}

void file_print_map(t_map map)
{
    FILE *output = fopen("map.txt", "wt");
    for (int i = 0; i < map.height; i++) {
        for (int j = 0; j < map.width; j++) {
            fprintf(output,"%c", _disp[map.data[i][j]]);
        }
        fprintf(output,"\n");
    }
}