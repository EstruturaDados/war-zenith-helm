#ifndef TERRITORY_H
#define TERRITORY_H
#include "player.h"

typedef struct
{
    char *name;
    Player *owner;
    int troops;
} Territory;

#endif