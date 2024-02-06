/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:54:24 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 14:54:24 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"

static inline t_dvector	_get_ddelta(t_dvector direction);
static inline t_vector	_get_idelta(t_ray const *ray);

void	ray_init(t_ray *self, t_camera const *camera, t_dvector pos, size_t n)
{
	self->start_x = (double)n / (double)CBD_RC_N_RAY_DFL * 2.0 - 1.0;
	self->dpos = pos;
	self->ipos = (t_point){pos.x, pos.y};
	self->direction = (t_dvector){
		camera->direction.x + camera->plane.x * self->start_x,
		camera->direction.y + camera->plane.y * self->start_x};
	self->ddelta = _get_ddelta(self->direction);
	self->idelta = _get_idelta(self);
}

static inline t_dvector	_get_ddelta(t_dvector direction)
{
	t_dvector	delta;

	if (direction.x == 0)
		delta.x = HUGE_VAL;
	else
		delta.x = fabs(1 / direction.x);
	if (direction.y == 0)
		delta.y = HUGE_VAL;
	else
		delta.y = fabs(1 / direction.y);
	return (delta);
}

static inline t_vector	_get_idelta(t_ray const *ray)
{
	t_vector	idelta;

	if (ray->direction.x < 0)
		idelta.x = -1;
	else if (ray->direction.x == HUGE_VAL)
		idelta.x = 0;
	else
		idelta.x = 1;
	if (ray->direction.y < 0)
		idelta.y = -1;
	else if (ray->direction.y == HUGE_VAL)
		idelta.y = 0;
	else
		idelta.y = 1;
	return (idelta);
}
