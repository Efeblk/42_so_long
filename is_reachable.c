#include "so_long.h"

int	char_counter(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == c)
				count++;
		}
	}
	return (count);
}

int	is_moveable(t_map *map, int i, int j)
{
	int	coin;

	coin = char_counter(map, 'C');
	if (map->map[i][j] == '0' || map->map[i][j] == 'C')
		return (1);
	if (map->map[i][j] == 'E' && coin == 0)
		return (1);
	return (0);
}

void	fill_reachable(t_map *map, int i, int j)
{
	if (is_moveable(map, i - 1, j))
		map->map[i - 1][j] = 'P';
	if (is_moveable(map, i + 1, j))
		map->map[i + 1][j] = 'P';
	if (is_moveable(map, i, j - 1))
		map->map[i][j - 1] = 'P';
	if (is_moveable(map, i, j + 1))
		map->map[i][j + 1] = 'P';
}

void	is_reached_everywhere(t_map *rt_map)
{
	int	i;
	int	j;

	i = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'E'
				|| rt_map->map[i][j] == 'C')
				exitor();
			j++;
		}
		i++;
	}
}

void	is_reachable(t_map *rt_map)
{
	int	i;
	int	j;
	int	tmp;

	while (1)
	{
		tmp = char_counter(rt_map, 'P');
		i = -1;
		while (rt_map->map[++i])
		{
			j = -1;
			while (rt_map->map[i][++j])
			{
				if (rt_map->map[i][j] == 'P')
					fill_reachable(rt_map, i, j);
			}
		}
		if (tmp == char_counter(rt_map, 'P'))
			break ;
	}
	is_reached_everywhere(rt_map);
}