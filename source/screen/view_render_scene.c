/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render_scene.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:08:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/21 20:05:04 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_screen.h"
#include "cbd_rc.h"
#include "point.h"
#include "MLX42_ext.h"
#include "fl_cei.h"

static void			render_wall(t_view *self, size_t i, struct s_screen_data d);
static uint32_t		_get_column(t_rc_result const *rc, t_texture const txr);
static int		_get_height(t_view const *self, double ray_length);
static t_texture_id	_get_txr(t_rc_result *rc);

void	view_render_scene(t_game *game, t_view *self, struct s_screen_data data)
{
	size_t	x;
	
	x = 0;
	mlx_image_fill(self->scene, 0x00000000);
	hrc_cast(game);
	while (x < CBD_RC_RES)
		render_wall(self, x++, data);
}

static void	render_wall(t_view *self, size_t i, struct s_screen_data data)
{
	t_texture_id const	txr = _get_txr(&data.rc->data[i]);
	int const			column = _get_column(&data.rc->data[i],
			data.assets->textures[txr]);
	int					line_height = _get_height(self, data.rc->data[i].length);
	uint32_t			draw_y = 0;
	double				read_y = 0;

	int draw_start = -line_height / 2 + CBD_HALF_HEIGHT + data.map->player.view_z + (data.rc->data->length);
	if (draw_start < 0) draw_start = 0;
	int draw_end = line_height / 2 + CBD_HALF_HEIGHT + data.map->player.view_z + (data.rc->data->length);
	if (draw_end >= CBD_SCREEN_H_DFL) draw_end = CBD_SCREEN_H_DFL - 1;
	
	double step = 1.0 * data.assets->textures[txr].data->height / line_height;
	double texture_pos = (draw_start - data.map->player.view_z - (data.rc->data->length) - CBD_HALF_HEIGHT + line_height / 2) * step;
	while (draw_y < line_height)
	{
		int texture_y = (int)texture_pos & (data.assets->textures[txr].data->height - 1);
		mlx_put_pixel_safe(self->scene, i, self->horizon - line_height / 2 + draw_y,
			mlx_texture_read(data.assets->textures[txr].data, column, texture_y));
		texture_pos += step;
		draw_y++;
	}
}

// static void	render_wall(t_view *self, size_t i, struct s_screen_data data)
// {
// 	t_texture_id const	txr = _get_txr(&data.rc->data[i]);
// 	int const			column = _get_column(&data.rc->data[i],
// 			data.assets->textures[txr]);
// 	uint32_t			height = _get_height(self, data.rc->data[i].length);
// 	uint32_t			draw_y;
// 	double				read_y;

// 	draw_y = 0;
// 	read_y = 0;
// 	double fog = 0;
// 	fog = data.rc->data[i].length * self->fog_constant / self->max_distance;
// 	while (draw_y < height)
// 	{
// 		// mlx_put_pixel_safe(self->scene, i, self->horizon - height / 2 + draw_y,
// 		// 	mlx_texture_read_fog(data.assets->textures[txr].data, column, read_y, fog));

// 		mlx_put_pixel_safe(self->scene, i, self->horizon - height / 2 + draw_y,
// 			mlx_texture_read(data.assets->textures[txr].data, column, read_y));
// 		read_y += data.assets->textures[txr].data->height / (double)height;
// 		draw_y++;
// 	}
// }


static uint32_t	_get_column(t_rc_result const *rc, t_texture const txr)
{
	double	integral;

	if (rc->isct == ISCT_V)
		return (modf(rc->end.y, &integral) * txr.data->width);
	return (modf(rc->end.x, &integral) * txr.data->width);
}

static int	_get_height(t_view const *self, double ray_length)
{
	if (ray_length == 1)
		return (self->wall_height);
	return (self->wall_height / ray_length);
}

static t_texture_id	_get_txr(t_rc_result *rc)
{
	if (rc->isct == ISCT_V)
	{
		if (rc->direction.x < 0)
			return (EAST_WALL);
		return (WEST_WALL);
	}
	if (rc->direction.y < 0)
		return (SOUTH_WALL);
	return (NORTH_WALL);
}
