/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render_scene.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:08:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/30 14:13:39 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "MLX42_ext.h"
#include "hrc.h"
#include "view_utils.h"

static void	init_render_wall(t_view *self, struct s_screen_data data, size_t x);

void	view_render_scene(t_game *game, t_view *self, struct s_screen_data data)
{
	size_t			x;

	x = -1;
	mlx_image_fill(data.view->scene, 0x00000000);
	if (game->bonus)
		hrc_cast(game);
	while (++x < CBD_RC_RES)
		init_render_wall(self, data, x);
}

static double	compute_fog(struct s_screen_data data, size_t i)
{
	if (*data.bonus)
		return (data.rc->data[i].length * data.view->fog_constant
			/ data.view->max_distance);
	return (0);
}

static void	render_wall(t_texture_id txr, int line_height,
					struct s_screen_data data, size_t i)
{
	const int		column = _get_column(&data.rc->data[i],
			data.assets->textures[txr]);
	const double	step
		= 1.0 * data.assets->textures[txr].data->height / line_height;
	int				draw_start;
	int				draw_end;
	double			texture_pos;

	draw_start = -line_height / 2 + CBD_HALF_HEIGHT + data.map->player.view_z;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + CBD_HALF_HEIGHT + data.map->player.view_z;
	if (draw_end > CBD_SCREEN_H_DFL)
		draw_end = CBD_SCREEN_H_DFL;
	texture_pos = (draw_start - data.map->player.view_z
			- CBD_HALF_HEIGHT + line_height / 2) * step;
	while (draw_start < draw_end)
	{
		mlx_put_pixel_safe(data.view->scene, i, draw_start,
			mlx_texture_read_fog(data.assets->textures[txr].data,
				column, texture_pos, compute_fog(data, i)));
		texture_pos += step;
		draw_start++;
	}
}

static void	init_render_wall(t_view *self, struct s_screen_data data, size_t x)
{
	const int			line_height
		= _get_height(self, data.rc->data[x].length);
	const t_texture_id	txr = _get_txr(&data.rc->data[x]);

	render_wall(txr, line_height, data, x);
}
