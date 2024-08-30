/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:33:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/11 16:09:34 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_screen.h"

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
		self->plane = dvc_scale(self->plane, 1.0 / CBD_VIEW_ZOOM_FACTOR);
		return (0);
	}
	return (1);
}

int	camera_zoom_out(t_camera *self)
{
	double const	len = dvc_len(self->plane);

	if (len < CBD_RC_ZOOM_MAX)
	{
		self->plane = dvc_scale(self->plane, CBD_VIEW_ZOOM_FACTOR);
		return (0);
	}
	return (1);
}
