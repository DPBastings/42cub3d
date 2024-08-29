/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hrc.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 16:55:25 by tim           #+#    #+#                 */
/*   Updated: 2024/08/29 16:39:52 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hrc.h"

static void			hrc_render(t_game *self, t_hrc *hrc,
						t_hrc_data *data, int y);

void	hrc_init(t_game *self)
{
	t_hrc	*hrc;

	hrc = malloc(sizeof(t_hrc));
	if (!hrc)
		cbd_mlx_terminate(self, CBD_EGENERIC);
	hrc->data = malloc(sizeof(t_hrc_data));
	if (!hrc->data)
		return (free(hrc), cbd_mlx_terminate(self, CBD_EGENERIC));
	hrc->floor = texture_init(self, "./assets/textures/wall_green.png");
	hrc->ceilling = texture_init(self, "./assets/textures/wall.png");
	self->hrc = hrc;
}

void	hrc_deinit(t_hrc *hrc)
{
	if (!hrc)
		return ;
	if (hrc->data)
	{
		free(hrc->data);
		hrc->data = NULL;
	}
	if (hrc->ceilling)
	{
		texture_deinit(hrc->ceilling);
		free(hrc->ceilling);
		hrc->ceilling = NULL;
	}
	if (hrc->floor)
	{
		texture_deinit(hrc->floor);
		free(hrc->floor);
		hrc->floor = NULL;
	}
	if (hrc)
		free(hrc);
	hrc = NULL;
}

void	hrc_cast(t_game *self)
{
	int			y;
	t_hrc_data	*data;

	data = self->hrc->data;
	y = -1;
	while (++y < CBD_SCREEN_H_DFL)
	{
		data->is_floor = y > CBD_HALF_HEIGHT + self->map.player.view_z;
		compute_ray_direction(data, self->map.player, self->rc.camera);
		if (data->is_floor)
			data->pos_y = y - CBD_HALF_HEIGHT - self->map.player.view_z;
		else
			data->pos_y = CBD_HALF_HEIGHT - y + self->map.player.view_z;
		data->row_distance = (double)CBD_HALF_HEIGHT / data->pos_y;
		compute_step(data, self->map.player);
		hrc_render(self, self->hrc, data, y);
	}
}

static void	hrc_render(t_game *self, t_hrc *hrc, t_hrc_data *data, int y)
{
	int			x;
	uint32_t	cl;
	double		fog;

	fog = data->row_distance * self->screen.view.fog_constant
		/ self->screen.view.max_distance;
	x = -1;
	cl = 0;
	while (++x < CBD_SCREEN_W_DFL)
	{
		update_txr_coord(hrc, data);
		if (data->is_floor)
			cl = mlx_texture_read_fog(hrc->floor->data, data->texture_coord.x,
					data->texture_coord.y, 0);
		else
			cl = mlx_texture_read_fog(hrc->ceilling->data,
					data->texture_coord.x,
					data->texture_coord.y, 0);
		mlx_put_pixel_safe(self->screen.view.scene, x, y, cl);
	}
}
