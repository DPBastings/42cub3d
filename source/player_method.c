/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_method.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 23:42:42 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 13:49:55 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"
#include "cbd_map.h"

#include <stdio.h>

#define MARGIN	1.1

static inline t_dpoint	get_dest(t_player const *p, t_direction dir);

t_object	*player_collide(t_player const *self, t_map *map, t_direction dir)
{
	t_dpoint const	dest = get_dest(self, dir);

	printf("%lf;%lf -> %lf;%lf\n", self->pos.x, self->pos.y, dest.x, dest.y);
	return (map_accessd(map, dest));
}

static inline t_dpoint	get_dest(t_player const *self, t_direction dir)
{
	if (dir == DIR_FORWARD)
		return ((t_dpoint){
			self->pos.x + self->delta.x,
			self->pos.y + self->delta.y});
	else if (dir == DIR_BACKWARD)
		return ((t_dpoint){
			self->pos.x - self->delta.x,
			self->pos.y - self->delta.y});
	else if (dir == DIR_LEFT)
		return ((t_dpoint){
			self->pos.x + self->delta.y,
			self->pos.y - self->delta.x});
	else if (dir == DIR_RIGHT)
		return ((t_dpoint){
			self->pos.x - self->delta.y,
			self->pos.y + self->delta.x});
	return (self->pos);
}
