#ifndef TYPES_H
#define TYPES_H

typedef struct
{
    char *name;
    char *color;
    int number_troops;
} Territory;

enum
{
    MAX_TERRITORIES = 5
};

#endif