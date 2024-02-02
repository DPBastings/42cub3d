/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_method.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 23:42:42 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:13:27 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"
#include "cbd_map.h"

static inline t_dpoint	get_dest(t_player const *p, t_direction dir);

t_object	*player_collide(t_player const *self, t_map *map, t_direction dir)
{
	t_dpoint const	dest = get_dest(self, dir);

	return (map_accessd(map, dest));
}

static inline t_dpoint	get_dest(t_player const *p, t_direction dir)
{
	if (dir == DIR_FORWARD)
		return ((t_dpoint){p->pos.x + p->delta.x, p->pos.y + p->delta.y});
	else if (dir == DIR_BACKWARD)
		return ((t_dpoint){p->pos.x - p->delta.x, p->pos.y - p->delta.y});
	else if (dir == DIR_LEFT)
		return ((t_dpoint){p->pos.x - p->delta.y, p->pos.y - p->delta.x});
	else if (dir == DIR_RIGHT)
		return ((t_dpoint){p->pos.x + p->delta.y, p->pos.y + p->delta.x});
	return (p->pos);
}
