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
	camera_zoom(self, zoom);
}

void	camera_rotate(t_camera *self, double rad)
{
	self->direction = dvc_rotate(self->direction, rad);
	self->plane = dvc_rotate(self->plane, rad);
}

void	camera_zoom(t_camera *self, double zoom)
{
	zoom = fabs(modf(zoom, NULL));
	self->plane = dvc_rotate(
		dvc_mult(self->direction, (t_dvector){zoom, zoom},
		M_PI_2);
}
	
