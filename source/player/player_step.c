/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_step.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 16:52:05 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/13 16:22:21 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"
#include "cbd_map.h"

void	player_step_forward(t_player *self, t_map const *map)
{
	double const	nx = self->pos.x + self->delta_m.x;
	double const	ny = self->pos.y + self->delta_m.y;

	if (map_caccessd(map, (t_dpoint){nx, self->pos.y})->type != OBJ_WALL)
		self->pos.x = nx;
	if (map_caccessd(map, (t_dpoint){self->pos.x, ny})->type != OBJ_WALL)
		self->pos.y = ny;
}

void	player_step_backward(t_player *self, t_map const *map)
{
	double const	nx = self->pos.x - self->delta_m.x;
	double const	ny = self->pos.y - self->delta_m.y;

	if (map_caccessd(map, (t_dpoint){nx, self->pos.y})->type != OBJ_WALL)
		self->pos.x = nx;
	if (map_caccessd(map, (t_dpoint){self->pos.x, ny})->type != OBJ_WALL)
		self->pos.y = ny;
}

void	player_step_left(t_player *self, t_map const *map)
{
	double const	nx = self->pos.x + self->delta_m.y;
	double const	ny = self->pos.y - self->delta_m.x;

	if (map_caccessd(map, (t_dpoint){nx, self->pos.y})->type != OBJ_WALL)
		self->pos.x = nx;
	if (map_caccessd(map, (t_dpoint){self->pos.x, ny})->type != OBJ_WALL)
		self->pos.y = ny;
}

void	player_step_right(t_player *self, t_map const *map)
{
	double const	nx = self->pos.x - self->delta_m.y;
	double const	ny = self->pos.y + self->delta_m.x;

	if (map_caccessd(map, (t_dpoint){nx, self->pos.y})->type != OBJ_WALL)
		self->pos.x = nx;
	if (map_caccessd(map, (t_dpoint){self->pos.x, ny})->type != OBJ_WALL)
		self->pos.y = ny;
}

/*void	player_step_backward(t_player *self, t_map const *map)
{
	self->pos.x -= self->delta_m.x;
	self->pos.y -= self->delta_m.y;
}

void	player_step_left(t_player *self, t_map const *map)
{
	self->pos.x += self->delta_m.y;
	self->pos.y -= self->delta_m.x;
}

void	player_step_right(t_player *self, t_map const *map)
{
	self->pos.x -= self->delta_m.y;
	self->pos.y += self->delta_m.x;
}*/