/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 13:09:07 by tcensier      #+#    #+#                 */
/*   Updated: 2024/03/25 18:56:07 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "cbd_error.h"
#include <stdio.h>

static uint32_t	_get_column(t_rc_result const *rc, t_texture const txr)
{
	double	integral;

	if (rc->isct == ISCT_V)
		return (modf(rc->end.y, &integral) * txr.data->width);
	return (modf(rc->end.x, &integral) * txr.data->width);
}

static uint32_t	_get_height(t_view const *self, double ray_length)
{
	if (ray_length == 0)
		return (self->wall_height);
	return (self->wall_height / ray_length);
}

void	sprite_casting(t_game *self)
{
	t_player player = self->map.player;
	t_sprite *rock = self->sprites;
	t_rc rc = self->rc;
	t_camera cam = self->rc.camera;
	t_view view = self->screen.view;
	
	//printf("rock_w: %d | rock_h: %d\n", rock->texture->data->width, rock->texture->data->height);

	double sprite_dist = (player.pos.x - rock->x) * (player.pos.x - rock->x) + (player.pos.y - rock->y) * (player.pos.y - rock->y);
	double sp_x = rock->x - player.pos.x;
	double sp_y = rock->y - player.pos.y;
	double invdet = 1.0 / (cam.plane.x * player.delta_o.y - player.delta_o.x * cam.plane.y);
	
	double transX = invdet * (player.delta_o.y * rock->x - player.delta_o.x * rock->y);
	double transY = invdet * (-cam.plane.y * rock->x + cam.plane.x * rock->y);
	
	int sprite_screen_x = ((int)(CBD_VIEW_W_DFL/2) * (1 + transX / transY));
	//printf("sprite_screen_x: %i\n", sprite_screen_x);
	int sprite_height = abs((int)(CBD_VIEW_H_DFL/ transY));
	int draw_start_y = -sprite_height / 2 + CBD_VIEW_H_DFL / 2;
	if (draw_start_y < 0) draw_start_y = 0;
	int draw_end_y = sprite_height / 2 + CBD_VIEW_H_DFL / 2;
	if (draw_end_y >= CBD_VIEW_H_DFL) draw_end_y = CBD_VIEW_H_DFL - 1;
	
	int sprite_width = sprite_height;
	int draw_start_x = -sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0) draw_start_x = 0;
	int draw_end_x = sprite_width / 2 + sprite_screen_x;
	if (draw_end_y >= CBD_VIEW_W_DFL) draw_end_y = CBD_VIEW_W_DFL - 1;

	int stripe = draw_start_x;
	while (stripe < draw_end_x)
	{
		int txr_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * rock->texture->data->width / sprite_width) / 256;
		if (transY > 0 && stripe > 0 && stripe < CBD_VIEW_W_DFL && transY < rc.data[stripe].length)
		{
			int y = draw_start_y;
			while (y < draw_end_y)
			{
				int d = y * 256 - CBD_SCREEN_H_DFL * 128 + sprite_height * 128;
				//printf("d: %i\n | rock_h: %d | sprite_h: %d", d, rock->texture->data->height, sprite_height);
				int txr_y = ((d * rock->texture->data->height) / sprite_height) / 256;
				//uint32_t cl = mlx_texture_read(rock->texture, txr_x, txr_y);
				//printf("txr_x: %i | txr_y: %i\n", txr_x, txr_y);
				mlx_put_pixel_safe(view.scene, stripe, y, 0xffff00 );
				y++;
			}
			

			
			// //mlx_image_to_window(self->mlx, rock->img, draw_start_x, draw_end_x);
			// // printf("in there\n");
			// int const col = _get_column(&rc.data[stripe], *rock->texture);
			// int y = draw_start_y;
			// double read_y = 0;
			// while (y < draw_end_y)
			// {
			// 	//mlx_texture_read(rock->texture, col, read_y);
			// 	//mlx_put_pixel_safe(view.scene, stripe, y, 0x0000000);
			// 	mlx_put_pixel(view.scene, stripe, view.horizon - draw_end_y / 2 + y, 0xffffff);
			// 	y++;
			// 	read_y += rock->texture->data->height / (double)draw_end_y;
			// 	printf("ry: %f\n", read_y);
			// }
		}
		stripe++;
	}
	 
}

void	sprite_draw(t_game *self)
{
	t_sprite *rock;

	rock = self->sprites;
	if (mlx_image_to_window(self->mlx, rock->img, 0, 0) == -1)
		cbd_terminate(CBD_EGENERIC);
}

void	init_sprites(t_game *self)
{
	t_sprite 	*rock;
	t_texture 	*txr;
	
	rock = malloc(sizeof(t_sprite));
	if (!rock)
		cbd_terminate(CBD_EGENERIC);
	txr = malloc(sizeof(t_texture));
	if (!txr)
	{
		free(rock);
		cbd_terminate(CBD_EGENERIC);
	}
	
	txr->path = ft_strdup("./assets/textures/sprites/rock.png");
	if (!txr->path)
	{
		free(rock);
		free(txr);
		cbd_terminate(CBD_EGENERIC);
	}
	texture_load(txr);
	rock->x = 2.0;
	rock->y = 2.0;
	rock->texture = txr;
	printf("rock_w: %d | rock_h: %d\n", rock->texture->data->width, rock->texture->data->height);
	self->sprites = rock;
}

void	sort_sprites(int *order, double *dist, int n)
{
	return ;
}