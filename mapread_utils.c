#include "so_long.h"
#include <stdio.h>

void mapfree(t_map *map)
{
    int i;
    i = 0;
    while (map->map[i])
		free(map->map[i++]);
	free(map->map[i++]);
	free(map->map);
}

void mallocmap (t_map *map)
{
    map->height = 0;
    map->width = 0;
    map->map = (char **)ft_calloc(1, 1);
    map->c = 0;
    map->e = 0;
    map->p = 0;
}

void writetomap (t_map *map, char *tmp_map)
{
    int line;
    int word;

    line = 0;
    if (!map)
        exitor();
    map->map = (char **)malloc((map->height + 1) * sizeof(char *));
    while (*tmp_map)
    {
        word = 0;
        map->map[line] = (char *)malloc((map->width + 1) * sizeof(char));
        while (*tmp_map && *tmp_map != '\n')
        {
            map->map[line][word] = *tmp_map;
            tmp_map++;
            word++;
        }
        map->map[line][word] = '\0'; 
        line++;
        tmp_map++;
    }
    isallone(map->map[line - 1]);
    exitcharacter(' ', 1, map);
    map->map[line] = 0;
}

void isallone(char *mapline)
{
    while (*mapline)
    {
        if (*mapline != '1' && *mapline != '\n')
            exitor();
        mapline++;
    }  
}

void exitcharacter(char a, int isended, t_map *map)
{
    if (a == 'P')
        map->p += 1;
    if (a == 'E')
        map->e += 1;
    if (a == 'C')
        map->c += 1;
    if (map->p > 1 || map->e > 1 )
        exitor();
    if (isended)
    {
        if (map->p < 1 || map->e < 1 || map->c < 1)
            exitor();
    }
}