/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rc_cast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 18:09:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 16:08:37 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_map.h"

void	rc_cast(t_rc *self, t_map const *map)
{
	size_t	i;
	double	angle;

	i = 0;
	angle = map->player.view_x / 2;
	while (i < self->size)
	{
		ray_init(&self->rays[i], angle, map->player.pos);
		ray_travel(&self->rays[i], map);
		++i;
		angle += self->radpr;
	}
}

void	ray_init(t_ray *self, double angle, t_dpoint origin)
{
	self->angle = angle;
	self->end = origin;
}

#include <stdio.h>

void	ray_travel(t_ray *self, t_map const *map)
{
	t_dpoint const	delta = get_ray_delta(self->angle);

	while (map_caccessd(map, self->end)->type != OBJ_WALL)
	{
		self->end.x += delta.x;
		self->end.y += delta.y;
	}
	//printf("hit a wall at %lf;%lf\n", self->end.x, self->end.y);
}