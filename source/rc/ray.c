/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 14:54:24 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/22 13:45:58 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"

#include <math.h>

static inline void	_init_delta_edge(t_ray *ray);
static inline void	_init_delta_grid(t_ray *ray);
static inline void	_init_ctr(t_ray *ray);

void	ray_init(t_ray *self, t_camera const *camera, t_dvector pos, size_t n)
{
	double const	start = 2 * n / (double)CBD_RC_RES - 1.0;

	self->pos = pos;
	self->pos_grid = point_from_dpoint(pos);
	self->direction = (t_dvector){
		camera->direction.x + camera->plane.x * start,
		camera->direction.y + camera->plane.y * start};
	_init_delta_edge(self);
	_init_delta_grid(self);
	_init_ctr(self);
}

static inline void	_init_delta_edge(t_ray *self)
{
	if (self->direction.x == 0)
		self->delta_edge.x = HUGE_VAL;
	else
		self->delta_edge.x = fabs(1 / self->direction.x);
	if (self->direction.y == 0)
		self->delta_edge.y = HUGE_VAL;
	else
		self->delta_edge.y = fabs(1 / self->direction.y);
}

static inline void	_init_delta_grid(t_ray *self)
{
	if (self->direction.x < 0)
		self->delta_grid.x = -1;
	else if (self->direction.x == 0)
		self->delta_grid.x = 0;
	else
		self->delta_grid.x = 1;
	if (self->direction.y < 0)
		self->delta_grid.y = -1;
	else if (self->direction.y == 0)
		self->delta_grid.y = 0;
	else
		self->delta_grid.y = 1;
}

static inline void	_init_ctr(t_ray *sf)
{
	if (sf->direction.x < 0)
		sf->ctr.x = (sf->pos.x - sf->pos_grid.x) * sf->delta_edge.x;
	else
		sf->ctr.x = (sf->pos_grid.x + 1.0 - sf->pos.x) * sf->delta_edge.x;
	if (sf->direction.y < 0)
		sf->ctr.y = (sf->pos.y - sf->pos_grid.y) * sf->delta_edge.y;
	else
		sf->ctr.y = (sf->pos_grid.y + 1.0 - sf->pos.y) * sf->delta_edge.y;
}
