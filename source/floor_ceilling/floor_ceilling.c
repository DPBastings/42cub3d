/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_ceilling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 16:55:25 by tim           #+#    #+#                 */
/*   Updated: 2024/08/20 16:11:50 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fl_cei.h"

static void		compute_ray_direction(t_hrc_data *data, t_player player, t_camera cam, int y);
static void 	compute_step(t_hrc_data *data, t_player player);
static void 	hrc_render(t_game *self, t_hrc *hrc, t_hrc_data *data, int y);
static void		init_textures(t_hrc *self);

void	hrc_init(t_game *self)
{
	t_hrc	*hrc;
	hrc = malloc(sizeof(t_hrc));
    if (!hrc)
        cbd_terminate(CBD_EGENERIC);
	hrc->data = malloc(sizeof(t_hrc_data));
	if (!hrc->data)
	{
		free(hrc);
		cbd_terminate(CBD_EGENERIC);
	}
	self->hrc = hrc;
	init_textures(hrc);
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
		compute_ray_direction(data, self->map.player, self->rc.camera, y);
		if (data->is_floor)
			data->pos_y = y - CBD_HALF_HEIGHT- self->map.player.view_z;
		else
			data->pos_y = CBD_HALF_HEIGHT - y + self->map.player.view_z;
		data->row_distance = (double)CBD_HALF_HEIGHT / data->pos_y;
		compute_step(data, self->map.player);
		hrc_render(self, self->hrc, data, y);
	}
}

static void 	hrc_render(t_game *self, t_hrc *hrc, t_hrc_data *data, int y)
{
	int			x;
	uint32_t 	cl;
	double fog;
	
	fog = data->row_distance * self->screen.view.fog_constant / self->screen.view.max_distance;
	x = -1;
	cl = 0;
	while (++x < CBD_SCREEN_W_DFL)
	{
		data->cell.x = (int)data->floor_coord.x;
		data->cell.y = (int)data->floor_coord.y;
		data->texture_coord.x = (int)(hrc->floor->data->width * (data->floor_coord.x - data->cell.x)) & (hrc->floor->data->width - 1);
		data->texture_coord.y = (int)(hrc->floor->data->height * (data->floor_coord.y - data->cell.y)) & (hrc->floor->data->height - 1);
		data->floor_coord.x += data->floor_step.x;
		data->floor_coord.y += data->floor_step.y;
		//cl = mlx_texture_read(hrc->ceilling->data, data->texture_coord.x, data->texture_coord.y);
		if (data->is_floor)
		{
			cl = mlx_texture_read_fog(hrc->floor->data, data->texture_coord.x, data->texture_coord.y, fog);
			mlx_put_pixel_safe(self->screen.view.scene, x, y, cl);
		}
		else
		{
			cl = mlx_texture_read_fog(hrc->ceilling->data, data->texture_coord.x, data->texture_coord.y, fog);
			mlx_put_pixel_safe(self->screen.view.scene, x, y, cl);
		}
	}
}

static void 	compute_step(t_hrc_data *data, t_player player)
{
	data->floor_step.x = data->row_distance * (data->raydir_1.x - data->raydir_0.x) / CBD_SCREEN_W_DFL;
	data->floor_step.y = data->row_distance * (data->raydir_1.y - data->raydir_0.y) / CBD_SCREEN_W_DFL;
	data->floor_coord.x = player.pos.x + data->row_distance * data->raydir_0.x;
	data->floor_coord.y = player.pos.y + data->row_distance * data->raydir_0.y;
}

static void		compute_ray_direction(t_hrc_data *data, t_player player, t_camera cam, int y)
{
	data->raydir_0.x = player.delta_o.x - cam.plane.x;
	data->raydir_0.y = player.delta_o.y - cam.plane.y;
	data->raydir_1.x = player.delta_o.x + cam.plane.x;
	data->raydir_1.y = player.delta_o.y + cam.plane.y;
}

static void		init_textures(t_hrc *self)
{
	t_texture	*floor;
	t_texture	*ceilling;
	
	floor = malloc(sizeof(t_texture));
	if (!floor)
		cbd_terminate(CBD_EGENERIC);
	ceilling = malloc(sizeof(t_texture));
	if (!ceilling)
	{
		free(floor);
		cbd_terminate(CBD_EGENERIC);
	}
	//floor->path = ft_strdup("./assets/textures/wall_green.png");
	floor->path = ft_strdup("./assets/bonus_textures/gray.png");
	if (!floor->path)
	{
		free(floor);
		free(ceilling);
		cbd_terminate(CBD_EGENERIC);
	}
	// ceilling->path = ft_strdup("./assets/textures/wall_green.png");
	ceilling->path = ft_strdup("./assets/bonus_textures/dark.png");
	if (!ceilling->path)
	{
		free(floor->path);
		free(floor);
		free(ceilling);
		cbd_terminate(CBD_EGENERIC);
	}
	texture_load(floor);
	texture_load(ceilling);
	
	self->floor = floor;
	self->ceilling = ceilling;
}