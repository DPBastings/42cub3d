/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/05/21 12:51:52 by tim           ########   odam.nl         */
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
	self->horizon = CBD_VIEW_H_DFL_2 + data.map->player.view_z;
	render_background(self);
	view_render_scene(game, self, data);
	
	// for (int x = 0; x < 1440; x++)
	// {
	// 	for (int y = 0; y < 900; y++)
	// 	{
	// 		if (self->px_buffer[900 * x + y])
	// 			mlx_put_pixel_safe(self->scene, x, y, self->px_buffer[900 * x + y]);
	// 	}
	// }

	int x = 0;
	int y = 0;
	while (x < 1440 && y < 900)
	{
		if (self->px_buffer[900 * x + y])
				mlx_put_pixel_safe(self->scene, x, y, self->px_buffer[900 * x + y]);
		if (y == 899 && x < 1440)
		{
			x++;
			y = 0;
		}
		y++;
	}
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CBD_BOX_H_DFL;
	self->floor->instances[0].y = self->horizon;
}
