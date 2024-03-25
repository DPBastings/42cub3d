/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_step.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:52:05 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/25 12:56:30 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"
#include "cbd_map.h"
#include <stdio.h>

static inline void	player_step(t_player *self, t_map const *map, t_dpoint cp,
	t_dpoint np);

void	player_step_forward(t_player *self, t_map const *map)
{
	t_dpoint const	cp = (t_dpoint){
		self->pos.x + (self->delta_m.x * PLAYER_HITBOX),
		self->pos.y + (self->delta_m.y * PLAYER_HITBOX)
	};
	t_dpoint const	np = (t_dpoint){
		self->pos.x + self->delta_m.x,
		self->pos.y + self->delta_m.y,
	};

	player_step(self, map, cp, np);
}

void	player_step_backward(t_player *self, t_map const *map)
{
	t_dpoint const	cp = (t_dpoint){
		self->pos.x - (self->delta_m.x * PLAYER_HITBOX),
		self->pos.y - (self->delta_m.y * PLAYER_HITBOX)
	};
	t_dpoint const	np = (t_dpoint){
		self->pos.x - self->delta_m.x,
		self->pos.y - self->delta_m.y,
	};

	player_step(self, map, cp, np);
}

void	player_step_left(t_player *self, t_map const *map)
{
	t_dpoint const	cp = (t_dpoint){
		self->pos.x + (self->delta_m.y * PLAYER_HITBOX),
		self->pos.y - (self->delta_m.x * PLAYER_HITBOX)
	};
	t_dpoint const	np = (t_dpoint){
		self->pos.x + self->delta_m.y,
		self->pos.y - self->delta_m.x,
	};

	player_step(self, map, cp, np);
}

void	player_step_right(t_player *self, t_map const *map)
{
	t_dpoint const	cp = (t_dpoint){
		self->pos.x - (self->delta_m.y * PLAYER_HITBOX),
		self->pos.y + (self->delta_m.x * PLAYER_HITBOX)
	};
	t_dpoint const	np = (t_dpoint){
		self->pos.x - self->delta_m.y,
		self->pos.y + self->delta_m.x,
	};

	player_step(self, map, cp, np);
}


static inline void	player_step(t_player *self, t_map const *map, t_dpoint cp,
	t_dpoint np)
{
	if (map_caccessd(map, (t_dpoint){cp.x, self->pos.y})->type != OBJ_WALL)
		self->pos.x = np.x;
	if (map_caccessd(map, (t_dpoint){self->pos.x, cp.y})->type != OBJ_WALL)
		self->pos.y = np.y;
}