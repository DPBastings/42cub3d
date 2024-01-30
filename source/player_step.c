/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:05 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 16:52:07 by dbasting         ###   ########.fr       */
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
	self->pos.y += self->delta.y;
}
