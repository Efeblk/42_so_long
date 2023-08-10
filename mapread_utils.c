#include "so_long.h"
#include <stdio.h>

void mallocmap (t_map *map, char *mapline)
{
    static int i = 0;
    i++;
    map->map = (char **)malloc(i + 1);
    map->map[i - 1] = (char *)malloc(ft_strlen1(mapline) + 1);

    //printf("%i", i);

    map->map[i - 1] = mapline;

    map->map[i + 1] = NULL;
    map->map[i - 1][ft_strlen1(mapline) - 1] = '\0';

    printf("%lu", sizeof(map));

    printf("%s",map->map[0]);
}