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

static int firstlinecheck(int firstlinebool, char *mapline)
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
    return(mapwidth);
}

void readmap(char *mapname)
{
    int fdmap;
    char *mapline;
    int firstlinebool;
    char *tmp_map;
    t_map map;

    firstlinebool = 1;
    mapline = "tmp";
    fdmap = open(mapname, O_RDONLY);
    tmp_map = ft_calloc(1, 1);
    mallocmap(&map);
    while (mapline != NULL)
    {
        mapline = get_next_line(fdmap);
        if (mapline == NULL)
            break;
        map.width = firstlinecheck(firstlinebool, mapline);
        firstlinebool = 0;
        checkline(mapline);
        tmp_map = ft_strjoin(tmp_map, mapline);
        map.height += 1;
    }
    printf("%s", tmp_map);
    printf("\n%i", map.height);
    printf("\n%i", map.width);
}

