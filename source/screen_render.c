/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_render.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:29:39 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"

static void	render_bg(t_screen *self, t_assets const *assets);
static void	render_walls(t_screen *self, struct s_renderer_data data);

void	screen_render(t_screen *self, struct s_renderer_data data)
{
	self->horizon = self->view->height / 2 + data.map->player.view_z * 48;
	render_bg(self, data.assets);
	render_walls(self, data);
	minimap_render(&self->minimap, data.map, data.rc);
}

static void	render_bg(t_screen *self, t_assets const *assets)
{
	t_upoint	cursor;

	cursor.y = 0;
	while (cursor.y < self->horizon)
	{
		cursor.x = 0;
		while (cursor.x < self->view->width)
		{
			mlx_put_pixel(self->view, cursor.x, cursor.y, assets->ceiling_rgba);
			++cursor.x;
		}
		++cursor.y;
	}
	while (cursor.y < self->view->height)
	{
		cursor.x = 0;
		while (cursor.x < self->view->width)
		{
			mlx_put_pixel(self->view, cursor.x, cursor.y, assets->floor_rgba);
			++cursor.x;
		}
		++cursor.y;
	}
}

static void	render_walls(t_screen *self, struct s_renderer_data data)
{
	(void) self;
	(void) data;
}
