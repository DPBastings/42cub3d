/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/04/08 17:01:13 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"

static void	render_background(t_view *self);

void	view_render(t_game *game, t_view *self, struct s_screen_data data)
{
	self->horizon = CBD_VIEW_H_DFL_2 + data.map->player.view_z;
	//render_background(self);
	view_render_scene(game, self, data);
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CBD_BOX_H_DFL;
	self->floor->instances[0].y = self->horizon;
}
