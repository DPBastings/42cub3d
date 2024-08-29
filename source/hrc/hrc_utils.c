/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hrc_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 18:59:51 by tim           #+#    #+#                 */
/*   Updated: 2024/08/29 15:50:34 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hrc.h"

void	update_txr_coord(t_hrc *hrc, t_hrc_data *data)
{
	data->cell.x = (int)data->floor_coord.x;
	data->cell.y = (int)data->floor_coord.y;
	data->texture_coord.x = (int)(hrc->floor->data->width
			* (data->floor_coord.x - data->cell.x))
		& (hrc->floor->data->width - 1);
	data->texture_coord.y = (int)(hrc->floor->data->height
			* (data->floor_coord.y - data->cell.y))
		& (hrc->floor->data->height - 1);
	data->floor_coord.x += data->floor_step.x;
	data->floor_coord.y += data->floor_step.y;
}

void	compute_step(t_hrc_data *data, t_player player)
{
	data->floor_step.x = data->row_distance
		* (data->raydir_1.x - data->raydir_0.x) / CBD_SCREEN_W_DFL;
	data->floor_step.y = data->row_distance
		* (data->raydir_1.y - data->raydir_0.y) / CBD_SCREEN_W_DFL;
	data->floor_coord.x = player.pos.x
		+ data->row_distance * data->raydir_0.x;
	data->floor_coord.y = player.pos.y
		+ data->row_distance * data->raydir_0.y;
}

void	compute_ray_direction(t_hrc_data *data,
						t_player player, t_camera cam)
{
	data->raydir_0.x = player.delta_o.x - cam.plane.x;
	data->raydir_0.y = player.delta_o.y - cam.plane.y;
	data->raydir_1.x = player.delta_o.x + cam.plane.x;
	data->raydir_1.y = player.delta_o.y + cam.plane.y;
}

t_texture	*texture_init(t_game *self, char *path)
{
	t_texture	*txr;

	if (!path)
		return (cbd_mlx_terminate(self, CBD_EGENERIC), NULL);
	txr = malloc(sizeof(t_texture));
	if (!txr)
		cbd_mlx_terminate(self, CBD_EGENERIC);
	txr->path = ft_strdup(path);
	if (!txr->path)
		return (free(txr), cbd_mlx_terminate(self, CBD_EGENERIC), NULL);
	texture_load(self, txr);
	return (txr);
}
