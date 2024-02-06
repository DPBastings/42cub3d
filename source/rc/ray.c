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

static inline t_dvector	_get_delta_l(t_dvector delta_p);
static inline t_vector	_get_delta_c(t_ray const *ray);
static inline t_dvector	_init_length(t_ray const *ray);

void	ray_init(t_ray *self, t_camera const *camera, t_dvector pos, size_t n)
{
	double const	start = (double)n / (double)CBD_RC_N_RAY_DFL * 2.0 - 1.0;

	self->pos = pos;
	self->cursor = (t_point){pos.x, pos.y};
	self->delta_p = (t_dvector){
		camera->direction.x + camera->plane.x * start,
		camera->direction.y + camera->plane.y * start};
	self->delta_l = _get_delta_l(self->delta_p);
	self->delta_c = _get_delta_c(self);
	self->length = _init_length(self);
}

static inline t_dvector	_get_delta_l(t_dvector delta_p)
{
	t_dvector	delta;

	if (delta_p.x == 0)
		delta.x = HUGE_VAL;
	else
		delta.x = fabs(1 / delta_p.x);
	if (delta_p.y == 0)
		delta.y = HUGE_VAL;
	else
		delta.y = fabs(1 / delta_p.y);
	return (delta);
}

static inline t_vector	_get_delta_c(t_ray const *ray)
{
	t_vector	delta_c;

	if (ray->delta_p.x < 0)
		delta_c.x = -1;
	else if (ray->delta_p.x == HUGE_VAL)
		delta_c.x = 0;
	else
		delta_c.x = 1;
	if (ray->delta_p.y < 0)
		delta_c.y = -1;
	else if (ray->delta_p.y == HUGE_VAL)
		delta_c.y = 0;
	else
		delta_c.y = 1;
	return (delta_c);
}

static inline t_dvector	_init_length(t_ray const *ray)
{
	t_dvector	length;

	if (ray->delta_p.x < 0)
		length.x = (0.0 - ray->cursor.x) * ray->delta_l.x;
	else
		length.x = (ray->cursor.x + 1.0 - 0.0) * ray->delta_l.x;
	if (ray->delta_p.y < 0)
		length.y = (0.0 - ray->cursor.y) * ray->delta_l.y;
	else
		length.y = (ray->cursor.y + 1.0 - 0.0) * ray->delta_l.y;
	return (length);
}
