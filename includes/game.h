#ifndef GAME_H
#define GAME_H
#include "map.h"

typedef struct
{
    Player players[2];
    Map map;
} Game;

#endif