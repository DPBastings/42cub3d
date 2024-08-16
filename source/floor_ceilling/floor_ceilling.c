/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_ceilling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 16:55:25 by tim           #+#    #+#                 */
/*   Updated: 2024/08/16 20:42:16 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fl_cei.h"

void	hrc_init(t_game *self)
{
	t_hrc	*hrc;
	hrc = malloc(sizeof(t_hrc));
    if (!hrc)
        cbd_terminate(CBD_EGENERIC);
	hrc->cam = self->rc.camera;
	hrc->data = malloc(sizeof(t_hrc_data));
	if (!hrc->data)
		cbd_terminate(CBD_EGENERIC);
	self->hrc = hrc;
}

static void hrc_render(t_game *self, int y)
{
	int	x;
	t_hrc_data *data;
	uint16_t cl;
	
	x = -1;
	data = self->hrc->data;
	while (++x < CBD_SCREEN_W_DFL)
	{
		data->cell.x = (int)data->floor_cord.x;
		data->cell.y = (int)data->floor_cord.y;
		data->texture_cord.x = (int)(self->floor->data->width * (data->floor_cord.x - data->cell.x)) & (self->floor->data->width - 1);
		data->texture_cord.y = (int)(self->floor->data->height * (data->floor_cord.y - data->cell.y)) & (self->floor->data->height - 1);
		data->floor_cord.x += data->floor_step.x;
		data->floor_cord.y += data->floor_step.y;
		cl = mlx_texture_read(self->floor->data, data->texture_cord.x, data->texture_cord.y);
		mlx_put_pixel_safe(self->screen.view.scene, x, y, cl);
	}
}

static void 	compute_step(t_hrc_data *data, t_player player)
{
	data->floor_step.x = data->row_distance * (data->raydir_1.x - data->raydir_0.x) / CBD_SCREEN_W_DFL;
	data->floor_step.y = data->row_distance * (data->raydir_1.y - data->raydir_0.y) / CBD_SCREEN_W_DFL;
	data->floor_cord.x = player.pos.x + data->row_distance * data->raydir_0.x;
	data->floor_cord.y = player.pos.y + data->row_distance * data->raydir_0.y;
}

static void		compute_ray_direction(t_hrc_data *data, t_player player, t_camera cam, int y)
{
	data->is_floor = y > CBD_SCREEN_H_DFL / 2 + player.view_z;
	data->raydir_0.x = player.delta_o.x - cam.plane.x;
	data->raydir_0.y = player.delta_o.y - cam.plane.y;
	data->raydir_1.x = player.delta_o.x + cam.plane.x;
	data->raydir_1.y = player.delta_o.y + cam.plane.y;
}

void	hrc_cast(t_game *self)
{
	int	y;
	t_hrc_data *data;
	
	data = self->hrc->data;
	y = -1;
	while (++y < CBD_SCREEN_H_DFL)
	{
		compute_ray_direction(data, self->map.player, self->hrc->cam, y);
		if (data->is_floor)
			data->pos_y = y - CBD_SCREEN_H_DFL / 2 - self->map.player.view_z;
		else
			data->pos_y = CBD_SCREEN_H_DFL / 2 - y + self->map.player.view_z;
		data->cam_pos_y = CBD_SCREEN_H_DFL * 0.5;
		data->row_distance = (double)(data->cam_pos_y) / data->pos_y;
		compute_step(data, self->map.player);
		hrc_render(self, y);
	}
}

void	rc_flcei(t_game *self)
{
	t_player	player = self->map.player;
	t_rc 		rc = self->rc;
	t_camera	cam = rc.camera;
	t_view		view = self->screen.view;
	t_texture 	*fl = self->floor;
	t_texture	*cei = self->ceilling;
	
	for (int y = 0; y < CBD_SCREEN_H_DFL; ++y)
	{
		bool is_fl = y > CBD_SCREEN_H_DFL / 2 + player.view_z;

		double ray_dir_x0 = player.delta_o.x - cam.plane.x;
		double ray_dir_y0 = player.delta_o.y - cam.plane.y;
		//rightmost ray
		double ray_dir_x1 = player.delta_o.x + cam.plane.x;
		double ray_dir_y1 = player.delta_o.y + cam.plane.y;	
		

		//printf("h: %d | z: %d\n", view.horizon, player.view_z);
		int curr_p = is_fl ? ( y - CBD_SCREEN_H_DFL / 2 - player.view_z) : (CBD_SCREEN_H_DFL / 2 - y + player.view_z);
		int cam_z_pos = CBD_SCREEN_H_DFL * 0.5;
		//printf("if fl: %d | p: %d | cam: %d| hor: %d | vz: %d\n", is_fl, curr_p, cam_z_pos, view.horizon, player.view_z);
		//horr distance from cam to floor for current row;
		double row_distance = (double)(cam_z_pos) / curr_p;
		
		//step calc avoid multip in inner loop
		double floor_stepx = row_distance * (ray_dir_x1 - ray_dir_x0) / CBD_SCREEN_W_DFL;
		double floor_stepy = row_distance * (ray_dir_y1 - ray_dir_y0) / CBD_SCREEN_W_DFL;

		//coord of leftmost column, will be updated stepb step
		double floor_x = player.pos.x + row_distance * ray_dir_x0;
		double floor_y = player.pos.y + row_distance * ray_dir_y0;
		double fog = row_distance / view.fog_constant * 5;
		for (int x = 0; x < CBD_SCREEN_W_DFL; x++)
		{
			//integer part of floor x and y
			int cell_x = (int)floor_x;
			int cell_y = (int)floor_y;
			//texture coord from fractionnal part
			int tx = (int)(fl->data->width * (floor_x - cell_x)) & (fl->data->width - 1);
			int ty = (int)(fl->data->height * (floor_y - cell_y)) & (fl->data->height - 1);

			floor_x += floor_stepx;
			floor_y += floor_stepy;
			
			// if (x < 1440 && y < 900)
			// {
			// 	if (row_distance < 4.0)
			// 		view.px_buffer[900 *x + y] = mlx_texture_read_fog(fl->data, tx, ty, fog);
			// 	else
			// 		view.px_buffer[900* x +y] = FOG_CL;
			// }
			uint32_t cl = mlx_texture_read(fl->data, tx, ty);
			mlx_put_pixel_safe(view.scene, x, y, cl);
		}
	}
}

void	init_flcei(t_game *self)
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
	floor->path = ft_strdup("./assets/textures/wall_blue_dark.png");
	if (!floor->path)
	{
		free(floor);
		free(ceilling);
		cbd_terminate(CBD_EGENERIC);
	}
	ceilling->path = ft_strdup("./assets/textures/wall.png");
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