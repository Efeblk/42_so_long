#include "so_long.h"
#include <stdio.h>

static int charvalid(char c)
{
    char *valid;
    valid = "01CEP";
    printf("%c", c);
    while (*valid)
    {
        if (*valid == c)
            return (1);
        valid++;
    }
    exitor();
    return(0);
}

static void checkline(char *line)
{
    while (*line && charvalid(*line))
    {
        line++;
    }
}

void readmap(char *mapname)
{
    int fdmap;
    char *mapline;

    fdmap = open(mapname, O_RDONLY);
    mapline = get_next_line(fdmap);
    checkline(mapline);
}

