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
    int last;

    last = ft_strlen1(line) - 1;
    if (line[0] != '1' || line[last] != '1')
        exitor();
    while (*line && charvalid(*line))
        line++;
}

static void isallone(char *mapline)
{
    while (*mapline)
    {
        if (*mapline != '1' && *mapline != '\n')
            exitor();
        mapline++;
    }  
}

static void firstlinecheck(int firstlinebool, char *mapline)
{
    static int mapwidth;
    int tmpwidth;

    if (firstlinebool)
    {
        mapwidth = ft_strlen1(mapline);
        isallone(mapline);
    }
    tmpwidth = ft_strlen1(mapline);
    if (mapwidth != tmpwidth)
        exitor();
}

void readmap(char *mapname)
{
    int fdmap;
    char *mapline;
    int firstlinebool;

    firstlinebool = 1;
    mapline = "tmp";
    fdmap = open(mapname, O_RDONLY);
    while (mapline != NULL)
    {
        mapline = get_next_line(fdmap);
        if (mapline == NULL)
            break;

        firstlinecheck(firstlinebool, mapline);
        firstlinebool = 0;
        checkline(mapline);     
    }
}

