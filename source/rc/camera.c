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
	(void) zoom;
	self->direction = direction;
	self->plane = dvc_rotate(self->direction, M_PI_2);
}

void	camera_rotate(t_camera *self, double rad)
{
	self->direction = dvc_rotate(self->direction, rad);
	self->plane = dvc_rotate(self->plane, rad);
}

void	camera_zoom(t_camera *self, double zoom)
{
	double	integral;

	zoom = fabs(modf(zoom, &integral));
	self->plane = dvc_rotate(
			dvc_mult(self->direction, (t_dvector){zoom, zoom}),
			M_PI_2);
}
