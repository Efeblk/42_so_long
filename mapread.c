#include "so_long.h"
#include <stdio.h>

static int charvalid(char c)
{
    char *valid;
    valid = "01CEP\n";
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
    int mapwidth;

    mapline = "tmp";
    fdmap = open(mapname, O_RDONLY);
    while (mapline != NULL)
    {
        mapline = get_next_line(fdmap);
        if (mapline == NULL)
        {
            break;
        }
        checkline(mapline);
        mapwidth = ft_strlen1(mapline);
        printf("\n%i", mapwidth);
    }
}

