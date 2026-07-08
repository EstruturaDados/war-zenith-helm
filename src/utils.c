#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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