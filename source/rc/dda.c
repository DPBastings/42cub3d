/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:00:13 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/12 15:00:14 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_map.h"

static inline t_isct	_dda_step(t_ray *ray);
static inline t_isct	_dda_step_v(t_ray *ray);
static inline t_isct	_dda_step_h(t_ray *ray);
static inline t_isct	_dda_end(t_ray *ray, int isct);

/**
 * @brief	Cast a singular ray by executing the digital differential analysis
 * 			(DDA) algorithm.
 */
t_isct	dda(t_ray *ray, t_map const *map)
{
	t_isct	isct;

	isct = ISCT_H;
	if (ray->delta_grid.x == 0)
		while (map_caccess(map, ray->pos_grid)->type != OBJ_WALL)
			isct = _dda_step_v(ray);
	else if (ray->delta_grid.y == 0)
		while (map_caccess(map, ray->pos_grid)->type != OBJ_WALL)
			isct = _dda_step_h(ray);
	else
		while (map_caccess(map, ray->pos_grid)->type != OBJ_WALL)
			isct = _dda_step(ray);
	return (_dda_end(ray, isct));
}

/**
 * @brief	Perform one DDA iteration/step.
 * 			
 * @return	A constant denoting this iteration's movement axis (ISCT_V if the
 * 			algorithm moved along the X axis, ISCT_H if it moved along the Y
 * 			axis).
 */
static inline t_isct	_dda_step(t_ray *ray)
{
	if (ray->ctr.x < ray->ctr.y)
		return (_dda_step_h(ray));
	return (_dda_step_v(ray));
}

static inline t_isct	_dda_step_h(t_ray *ray)
{
	ray->ctr.x += ray->delta_edge.x;
	ray->pos_grid.x += ray->delta_grid.x;
	return (ISCT_V);
}

static inline t_isct	_dda_step_v(t_ray *ray)
{
	ray->ctr.y += ray->delta_edge.y;
	ray->pos_grid.y += ray->delta_grid.y;
	return (ISCT_H);
}

static inline t_isct	_dda_end(t_ray *ray, int isct)
{
	if (isct == ISCT_V)
		ray->length = ray->ctr.x - ray->delta_edge.x;
	else
		ray->length = ray->ctr.y - ray->delta_edge.y;
	ray->pos.x += ray->length * ray->direction.x;
	ray->pos.y += ray->length * ray->direction.y;
	return (isct);
}
