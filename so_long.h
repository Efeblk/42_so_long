#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
    char **map;
    int width;
    int height;
}t_map;

int ft_strlen (char *c);
void exitor();

void bercheck (char *mapname);
void is_ber(char *mapname, int end);


#endif