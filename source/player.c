/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 17:28:55 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:54:23 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"

static double const	g_starting_angles[N_COMPASS] = {
	0,
	M_PI_2,
	M_PI,
	M_PI + M_PI_2,
};

void	player_init(t_player *self, t_point pt, t_compass_direction orientation)
{
	self->pos.x = pt.x + 0.5;
	self->pos.y = pt.y + 0.5;
	self->view_x = g_starting_angles[orientation];
	self->view_z = 0;
	self->delta = get_delta(self->view_x);
}
