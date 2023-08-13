#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"
typedef struct s_map
{
    char **map;
    int width;
    int height;
    int p;
    int c;
    int e;
}t_map;

int ft_strlen1 (char *c);
void exitor();

void bercheck (char *mapname);
void is_ber(char *mapname, int end);

void isallone(char *mapline);
void readmap(char *mapname);
void exitcharacter(char a, int isended, t_map *map);

void mallocmap (t_map *map);
void writetomap (t_map *map, char *tmp_map);

#endif