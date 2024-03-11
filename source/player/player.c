/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 17:28:55 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/11 17:04:46 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"

static t_dvector const	g_deltas[N_COMPASS] = {
	(t_dvector){1.0, 0.0},
	(t_dvector){0.0, 1.0},
	(t_dvector){-1.0, 0.0},
	(t_dvector){0.0, -1.0}
};

// static t_dvector normalize_vector(t_dvector direction)
// {
// 	double magnitude;

// 	magnitude = sqrt((direction.x * direction.x) + (direction.y * direction.y));
// 	direction.x = 
// }

void	player_init(t_player *self, t_point pt, t_compass_direction orientation)
{
	self->pos = (t_dpoint){pt.x + 0.5, pt.y + 0.5};
	self->delta_o = g_deltas[orientation];
	self->delta_m = (t_dvector){
		g_deltas[orientation].x * PLAYER_STEP_SPEED,
		g_deltas[orientation].y * PLAYER_STEP_SPEED};
	self->view_z = 0;
}
