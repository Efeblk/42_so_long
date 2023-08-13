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

typedef struct s_coins
{
	int		*coins_c;
	int		**coin_pos;
	void	*coin_img;
}	t_coins;

typedef struct s_player
{
	int		player_width;
	int		player_height;
	void	*player_img;
}	t_player;

typedef struct s_game
{
	t_map		*map;
	t_coins		*coins;
	t_player	*player;
}	t_game;

int ft_strlen1 (char *c);
void exitor();

void bercheck (char *mapname);
void is_ber(char *mapname, int end);

void isallone(char *mapline);
void readmap(char *mapname, int doreach, t_map *map, t_game *game);
void exitcharacter(char a, int isended, t_map *map, t_game *game);

t_map *mallocmap (t_map *map);
void mallocplayer(t_game *game);
void writetomap (t_map *map, char *tmp_map);
char *checkmap(t_map *map, char *tmp_map, int fdmap, t_game *game);
void mapfree(t_map *map);

int	char_counter(t_map *map, char c);
int	is_moveable(t_map *map, int i, int j);
void	fill_reachable(t_map *map, int i, int j);
void	is_reached_everywhere(t_map *rt_map);
void	is_reachable(t_map *rt_map);

#endif