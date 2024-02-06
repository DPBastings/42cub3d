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
	self->view_x -= PLAYER_TURN_SPEED;
	if (self->view_x < 0)
		self->view_x = M_PI * 2;
	self->delta = get_delta(self->view_x);
}

void	player_turn_right(t_player *self)
{
	self->view_x += PLAYER_TURN_SPEED;
	if (self->view_x >= M_PI * 2)
		self->view_x = 0;
	self->delta = get_delta(self->view_x);
}

void	player_turn_up(t_player *self)
{
	if (self->view_z < M_PI_2)
		self->view_z += PLAYER_TURN_SPEED;
}

void	player_turn_down(t_player *self)
{
	if (self->view_z >= -M_PI_2)
		self->view_z -= PLAYER_TURN_SPEED;
}
