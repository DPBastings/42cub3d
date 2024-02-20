/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_turn.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:52:09 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:46:57 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"
#include "cbd_screen.h"

#include <math.h>

void	player_turn_h(t_player *self, double rad)
{
	self->delta_o = dvc_rotate(self->delta_o, rad);
	self->delta_m = dvc_rotate(self->delta_m, rad);
}

void	player_turn_v(t_player *self, double delta)
{
	self->view_z += delta;
	if (self->view_z > CBD_VIEW_Z_MARGIN)
		self->view_z = CBD_VIEW_Z_MARGIN;
	else if (self->view_z < -CBD_VIEW_Z_MARGIN)
		self->view_z = -CBD_VIEW_Z_MARGIN;
}
