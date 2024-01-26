#ifndef CBD_MAP_H
# define CBD_MAP_H

# include "cbd.h"
# include <stddef.h>

struct s_map
{
	size_t	x_max;
	size_t	y_max;
	char	**contents;
}; // struct s_map

void	map_construct(t_map *map, size_t x_max, size_t y_max);
void	map_destroy(t_map *map);

#endif // CBD_MAP_H
