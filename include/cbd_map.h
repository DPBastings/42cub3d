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
# include "cbd_object.h"
# include "point.h"
# include "types.h"

# include <stddef.h>

/**
 * @brief	Map object.
 * 			Contains all information pertaining to gameplay.
 * @param x_size	The width of the map.
 * @param y_size	The height of the map.
 * @param objects	All objects that together comprise the level.
 * @param void_		A dummy object representing the space outside the map.
 * @param player	Player object.
 */
struct s_map
{
	int			x_size;
	int			y_size;
	t_object	**objects;
	t_object	void_;
	t_player	player;
}; // struct s_map

void		map_read(t_map *self, t_fd fd);
void		map_check(t_map *self);
void		map_deinit(t_map *self);

t_object	*map_access(t_map *self, t_point pt);
t_object	*map_accessd(t_map *self, t_dpoint dpt);

#endif // CBD_MAP_H
