/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/19 17:16:59 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"
#include "MLX42_ext.h"

static void	render_background(t_view *self);

void	view_render(t_game *game, t_view *self, struct s_screen_data data)
{
	self->horizon = CBD_HALF_HEIGHT + data.map->player.view_z;
	render_background(self);
	view_render_scene(game, self, data);
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CBD_BOX_H_DFL;
	self->floor->instances[0].y = self->horizon;
}