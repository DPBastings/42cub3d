/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_ceilling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 16:55:25 by tim           #+#    #+#                 */
/*   Updated: 2024/04/08 17:38:09 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fl_cei.h"

void	rc_flcei(t_game *self)
{
	t_player	player = self->map.player;
	t_rc 		rc = self->rc;
	t_camera	cam = rc.camera;
	t_view		view = self->screen.view;
	t_texture 	*fl = self->floor;
	t_texture	*cei = self->ceilling;
	
	for (int y = 0; y < CBD_SCREEN_H_DFL; y++)
	{
		//leftmost ray
		double ray_dir_x0 = player.delta_o.x - cam.plane.x;
		double ray_dir_y0 = player.delta_o.y - cam.plane.y;
		//rightmost ray
		double ray_dir_x1 = player.delta_o.x + cam.plane.x;
		double ray_dir_y1 = player.delta_o.y + cam.plane.y;	

		int curr_p = y - CBD_SCREEN_H_DFL / 2;
		double cam_z_pos = player.view_z;

		//horr distance from cam to floor for current row;
		double row_distance = cam_z_pos / curr_p;
		
		//step calc avoid multip in inner loop
		double floor_stepx = row_distance * (ray_dir_x1 - ray_dir_x0) / CBD_SCREEN_W_DFL;
		double floor_stepy = row_distance * (ray_dir_y1 - ray_dir_y0) / CBD_SCREEN_W_DFL;

		//coord of leftmost column, will be updated stepb step
		double floor_x = player.pos.x + row_distance * ray_dir_x0;
		double floor_y = player.pos.y + row_distance * ray_dir_y0;
		
		for (int x = 0; x < CBD_SCREEN_W_DFL; ++x)
		{
			//integer part of floor x and y
			int cell_x = (int)floor_x;
			int cell_y = (int)floor_y;
			//texture coord from fractionnal part
			int tx = (int)(fl->data->width * (floor_x - cell_x)) & (fl->data->width - 1);
			int ty = (int)(fl->data->height * (floor_y - cell_y)) & (fl->data->height - 1);

			floor_x += floor_stepx;
			floor_y += floor_stepy;
			
			uint32_t cl = mlx_texture_read(fl->data, tx, ty);
			mlx_put_pixel_safe(view.scene, x, view.horizon - CBD_SCREEN_H_DFL / 2 + y, cl);
			mlx_put_pixel_safe(view.scene, x, view.horizon - CBD_SCREEN_H_DFL / 2 + (CBD_SCREEN_H_DFL - y - 1), cl);
			
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