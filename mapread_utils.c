#include "so_long.h"
#include <stdio.h>

void mallocmap (t_map *map)
{
    map->height = 0;
    map->width = 0;
    map->map = (char **)ft_calloc(1, 1);
}