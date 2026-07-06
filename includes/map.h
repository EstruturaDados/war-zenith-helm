#ifndef MAP_H
#define MAP_H
#include "territory.h"

enum
{
    MAX_TERRITORIES = 8,
    MAX_BORDERS = 12
};

typedef struct
{
    Territory *t_1;
    Territory *t_2;
} Border;

typedef struct
{
    Territory territories[MAX_TERRITORIES];
    Border borders[MAX_BORDERS];
} Map;

#endif