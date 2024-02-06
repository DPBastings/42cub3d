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

static t_rc_result	_cast_ray(t_camera *camera, t_map const *map, size_t i)
{
	t_ray 		ray;
	t_rc_result	result;
	int			side;

	ray_init(&ray, camera, map->player.pos, i);
	result_init(&result, &ray);
	while (map_caccess(map, ray.ipos)->type != OBJ_WALL)
	{
		if (result.distance.x < result.distance.y)
		{
			result.distance.x += ray.ddelta.x;
			side = 0;
			ray.dpos.x += ray.ddelta.x;
			ray.ipos.x += ray.idelta.x;
		}
		else
		{
			result.distance.y += ray.ddelta.y;
			side = 1;
			ray.dpos.y += ray.ddelta.y;
			ray.ipos.y += ray.idelta.y;
		}
	}
	if (side == 0)
		result.distanced = result.distance.x - ray.ddelta.x;
	else
		result.distanced = result.distance.y - ray.ddelta.y;
	result.end = ray.dpos;
	return (result);
}

static void	result_init(t_rc_result *self, t_ray const *ray)
{
	if (ray->direction.x < 0)
		self->distance.x = (ray->dpos.x - ray->ipos.x) * ray->ddelta.x;
	else
		self->distance.x = (ray->ipos.x + 1.0 - ray->dpos.x) * ray->ddelta.x;
	if (ray->direction.y < 0)
		self->distance.y = (ray->dpos.y - ray->ipos.y) * ray->ddelta.y;
	else
		self->distance.y = (ray->ipos.y + 1.0 - ray->dpos.y) * ray->ddelta.y;
}
