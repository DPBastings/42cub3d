/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:52:42 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"

	// == CBD_VIEW_HEIGHT_DFL_2 + CBD_VIEW_Z_MARGIN
#define CEILING_OFFSET 800

static void	render_background(t_view *self);

void	view_render(t_view *self, struct s_screen_data data)
{
	self->horizon = CBD_VIEW_HEIGHT_DFL_2 + data.map->player.view_z;
	render_background(self);
	view_render_scene(self, data);
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CEILING_OFFSET;
	self->floor->instances[0].y = self->horizon;
}
