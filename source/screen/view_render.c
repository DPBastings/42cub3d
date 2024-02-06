/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 18:18:04 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"

#define CEILING_OFFSET 600 // CBD_VIEW_HEIGHT_DFL / 2 + PLAYER_VIEW_ZMAX

static void	render_background(t_view *self);

void	view_render(t_view *self, struct s_screen_data data)
{
	self->horizon = CBD_VIEW_HEIGHT_DFL / 2 + data.map->player.view_z;
	render_background(self);
	view_render_scene(self, data);
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CEILING_OFFSET;
	self->floor->instances[0].y = self->horizon;
}
