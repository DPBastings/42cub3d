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
	t_ray	ray;
	size_t	i;

	i = 0;
	while (i < CBD_RC_RES)
	{
		ray_init(&ray, &self->camera, map->player.pos, i);
		self->data[i].isct = dda(&ray, map);
		self->data[i].direction = ray.direction;
		self->data[i].end = ray.pos;
		self->data[i].length = ray.length;
		++i;
	}
}
