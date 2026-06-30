#include "territories.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

Territory *get_territories(int p)
{
    if (p == MAX_TERRITORIES)
    {
        Territory *ptr = malloc(MAX_TERRITORIES * sizeof(Territory));
        
        if (ptr == NULL)
            return NULL;
        
        return ptr;
    }

    puts("=========================");
    printf("     Territorio %d\n     ", p + 1);
    puts("=========================");

    char msg[64];

    snprintf(msg, sizeof(msg), "Digite o nome do territorio %d", p + 1);
    char *ptr_name = read_string(msg);
    if (ptr_name == NULL)
        return NULL;

    snprintf(msg, sizeof(msg), "Digite a cor do territorio %d", p + 1);
    char *ptr_color = read_string(msg);
    if (ptr_color == NULL)
    {
        free(ptr_name);

        return NULL;
    }
    
    snprintf(msg, sizeof(msg), "Digite a quantidade de tropas do territorio %d", p + 1);
    int quantity = read_positive_number(msg);
    if (quantity == -1)
    {
        free(ptr_color);
        free(ptr_name);

        return NULL;
    }
    
    Territory t = {
        ptr_name,
        ptr_color,
        quantity
    };

    Territory *territories = get_territories(p + 1);

    if (territories == NULL)
    {
        destroy_territory(&t);
        return NULL;
    }

    territories[p] = t;

    return territories;
}

void destroy_territory(Territory *t)
{
    free(t->name);
    free(t->color);

    t->name = NULL;
    t->color = NULL;
}