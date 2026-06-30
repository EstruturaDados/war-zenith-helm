#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(const char *msg)
{
    char buffer[256];

    printf("%s: ", msg);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return NULL;
    
    buffer[strcspn(buffer, "\n")] = '\0';

    char *ptr = malloc(strlen(buffer) + 1);
    if (ptr == NULL)
        return NULL;

    strcpy(ptr, buffer);

    return ptr;
}

// entrada inválida: -1
int read_positive_number(const char *msg)
{
    char buffer[32];
    int number;

    printf("%s: ", msg);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return -1;

    if (sscanf(buffer, "%d", &number) == 0)
        return -1;

    if (number < 1)
        return -1;

    return number;
}