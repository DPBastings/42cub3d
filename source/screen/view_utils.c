/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 15:18:44 by tim           #+#    #+#                 */
/*   Updated: 2024/08/28 18:16:22 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "view_utils.h"

int	_get_height(t_view const *self, double ray_length)
{
	if (ray_length == 1)
		return (self->wall_height);
	return (self->wall_height / ray_length);
}

uint32_t	_get_column(t_rc_result const *rc, t_texture const txr)
{
	double	integral;

	if (rc->isct == ISCT_V)
		return (modf(rc->end.y, &integral) * txr.data->width);
	return (modf(rc->end.x, &integral) * txr.data->width);
}

t_texture_id	_get_txr(t_rc_result *rc)
{
	if (rc->isct == ISCT_V)
	{
		if (rc->direction.x < 0)
			return (EAST_WALL);
		return (WEST_WALL);
	}
	if (rc->direction.y < 0)
		return (SOUTH_WALL);
	return (NORTH_WALL);
}
