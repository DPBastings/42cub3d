/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:33:07 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 11:33:07 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"

void	camera_init(t_camera *self, t_dvector direction, double zoom)
{
	self->direction = direction;
	self->zoom = zoom;
	self->plane = dvc_rotate(
		dvc_mult(self->direction, (t_dvector){self->zoom, self->zoom}),
		M_PI_2);
}

void	camera_rotate(t_camera *self, double rad)
{
	self->direction = dvc_rotate(self->direction, rad);
	self->plane = dvc_rotate(self->plane, rad);
}

void	camera_zoom(t_camera *self, double delta)
{
	self->zoom += delta;
	
	if (self->zoom < 0.7)
		self->zoom = 0.7;
	else if (self->zoom > 1.3)
		self->zoom = 1.3;
	self->plane = dvc_rotate(
			dvc_mult(self->direction, (t_dvector){self->zoom, self->zoom}),
			M_PI_2);
}
