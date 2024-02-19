/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:33:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 18:01:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"

void	camera_init(t_camera *self, t_dvector direction)
{
	self->direction = direction;
	self->plane = dvc_rotate(
			dvc_scale(self->direction, CBD_RC_ZOOM_DFL),
			M_PI_2);
}

void	camera_rotate(t_camera *self, double rad)
{
	self->direction = dvc_rotate(self->direction, rad);
	self->plane = dvc_rotate(self->plane, rad);
}

int	camera_zoom_in(t_camera *self)
{
	double const	len = dvc_len(self->plane);

	if (len > CBD_RC_ZOOM_MIN)
	{
		self->plane = dvc_scale(self->plane, 0.95);
		return (0);
	}
	return (1);
}

int	camera_zoom_out(t_camera *self)
{
	double const	len = dvc_len(self->plane);

	if (len < CBD_RC_ZOOM_MAX)
	{
		self->plane = dvc_scale(self->plane, 1.05);
		return (0);
	}
	return (1);
}