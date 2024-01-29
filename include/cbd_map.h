/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_map.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:36:02 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:39:15 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_MAP_H
# define CBD_MAP_H

# include "cbd.h"
# include "cbd_error.h"
# include "cbd_player.h"
# include "point.h"
# include "types.h"

# include <stddef.h>

struct s_map
{
	int			x_size;
	int			y_size;
	t_object	**contents;
	t_player	player;
}; // struct s_map

void		map_read(t_map *map, t_fd fd);
void		map_check(t_map *map);
void		map_deinit(t_map *map);

t_object	*map_access(t_map *self, t_point pt);
t_object	map_caccess(t_map const *self, t_point pt);

#endif // CBD_MAP_H
