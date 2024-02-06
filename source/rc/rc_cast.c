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

#include <stdio.h>

static t_rc_result	_cast_ray(t_camera *camera, t_map const *map, size_t n);
static void			result_init(t_rc_result *self, t_ray const *ray);

void	rc_cast(t_rc *self, t_map const *map)
{
	size_t	i;

	i = 0;
	while (i < CBD_RC_N_RAY_DFL)
	{
		self->data[i] = _cast_ray(&self->camera, map, i);
		++i;
	}
}

/**
 * @note	The algorithm can be broken down as follows:
 * 			1. Check whether the ray would hit a wall when moving to the next
 * 			grid slot:
 * 			a. If a vertical edge (i.e. the X) would be closer than a
 * 			horizontal edge (i.e. the Y side), add X to the distance traveled
 * 			and move the grid cursor horizontally.
 * 			b. Else, add Y to the distance and move the grid cursor vertically.
 * 			...
 */
static t_rc_result	_cast_ray(t_camera *camera, t_map const *map, size_t i)
{
	t_ray 		ray;
	t_rc_result	result;
	int			side;

	ray_init(&ray, camera, map->player.pos, i);
	result_init(&result, &ray);
	while (map_caccess(map, ray.cursor)->type != OBJ_WALL)
	{
		ray.pos = dvc_add(ray.pos, ray.delta_p);
		if (ray.length.x < ray.length.y)
		{
			side = 0;
			ray.length.x += ray.delta_l.x;
			ray.cursor.x += ray.delta_c.x;
		}
		else
		{
			side = 1;
			ray.length.y += ray.delta_l.y;
			ray.cursor.y += ray.delta_c.y;
		}
	}
	result.distance = ray.length;
	result.end = ray.pos;
	if (side == 0)
		result.distanced = result.distance.x - ray.delta_l.x;
	else
		result.distanced = result.distance.y - ray.delta_l.y;
	return (result);
}

static void	result_init(t_rc_result *self, t_ray const *ray)
{
	return;
	if (ray->delta_p.x < 0)
		self->distance.x = (ray->length.x - ray->cursor.x) * ray->delta_l.x;
	else
		self->distance.x = (ray->cursor.x + 1.0 - ray->length.x) * ray->delta_l.x;
	if (ray->delta_p.y < 0)
		self->distance.y = (ray->length.y - ray->cursor.y) * ray->delta_l.y;
	else
		self->distance.y = (ray->cursor.y + 1.0 - ray->length.y) * ray->delta_l.y;
}
