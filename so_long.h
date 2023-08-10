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
}t_map;

int ft_strlen1 (char *c);
void exitor();

void bercheck (char *mapname);
void is_ber(char *mapname, int end);

void readmap(char *mapname);

void mallocmap (t_map *map, char *mapline);
#endif