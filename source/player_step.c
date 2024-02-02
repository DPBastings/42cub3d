/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_step.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:52:05 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:13:37 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"

void	player_step_forward(t_player *self)
{
	self->pos.x += self->delta.x;
	self->pos.y += self->delta.y;
}

void	player_step_backward(t_player *self)
{
	self->pos.x -= self->delta.x;
	self->pos.y -= self->delta.y;
}

void	player_step_left(t_player *self)
{
	self->pos.x += self->delta.y;
	self->pos.y += self->delta.x;
}

void	player_step_right(t_player *self)
{
	self->pos.x -= self->delta.y;
	self->pos.y -= self->delta.x;
}
