/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_turn.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:52:09 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:18:24 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"

#include <math.h>

void	player_turn_left(t_player *self)
{
	self->delta_o = dvc_rotate(self->delta_o, -PLAYER_TURN_SPEED);
	self->delta_m = dvc_rotate(self->delta_m, -PLAYER_TURN_SPEED);
}

void	player_turn_right(t_player *self)
{
	self->delta_o = dvc_rotate(self->delta_o, PLAYER_TURN_SPEED);
	self->delta_m = dvc_rotate(self->delta_m, PLAYER_TURN_SPEED);
}

void	player_turn_up(t_player *self)
{
	if (self->view_z < PLAYER_VIEW_ZMAX)
		self->view_z += 10;
}

void	player_turn_down(t_player *self)
{
	if (self->view_z >= -PLAYER_VIEW_ZMAX)
		self->view_z -= 10;
}
