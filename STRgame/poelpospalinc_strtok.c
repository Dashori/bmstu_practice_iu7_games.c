#include "poelpospalinc_strtok.h"
#include <string.h>
#include <stdio.h>

char *memp;

char *strtok(char *string, char const *delim)
{
    if (string != NULL)
        memp = string;
    char *i = memp;

    while (strchr(delim, *i) && *i)
        i++;

    if (*i == 0)
        return NULL;
    char *w_beg = i;

    while (!strchr(delim, *i) && *i)
        i++;
    *i = 0;
    memp = ++i;
    
    return w_beg;
}
