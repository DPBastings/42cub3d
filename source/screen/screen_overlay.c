/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen_overlay.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 14:26:02 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/10 20:02:31 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_screen.h"
#include "cbd_error.h"

#include "MLX42_ext.h"
#include <stdio.h>
static t_texture_id const	g_txrids[N_SCREEN_OVERLAY_ICON] = {
	TXR_PAUSE, TXR_CROSSHAIR,
};

void	screen_overlay_init(t_screen_overlay *self, t_assets const *assets,
			mlx_t *mlx)
{
	t_screen_overlay_icon	i;

	self->bg = mlx_new_image(mlx, CBD_SCREEN_W_DFL, CBD_SCREEN_H_DFL);
	if (self->bg == NULL)
		cbd_terminate(CBD_EGENERIC);
	i = 0;
	while (i < N_SCREEN_OVERLAY_ICON)
	{
		self->icons[i] = mlx_texture_to_image(
			mlx,
			assets->textures[g_txrids[i]].data);
		if (self->icons[i] == NULL)
			cbd_terminate(CBD_EGENERIC);
		++i;
	}
}
void	screen_overlay_deinit(t_screen_overlay *self, mlx_t *mlx)
{
	t_screen_overlay_icon	i;

	i = 0;
	while (i < N_SCREEN_OVERLAY_ICON)
		mlx_delete_image(mlx, self->icons[i++]);
	mlx_delete_image(mlx, self->bg);
}

void	screen_overlay_draw(t_screen_overlay *self, mlx_t *mlx)
{
	t_screen_overlay_icon	i;
	t_point					pt;

	if (mlx_image_to_window(mlx, self->bg, 0, 0) == -1)
		cbd_terminate(CBD_EGENERIC);
	mlx_set_instance_depth(&self->bg->instances[0], CBD_Z_SCREEN_OVERLAY);
	i = 0;
	while (i < N_SCREEN_OVERLAY_ICON)
	{
		pt = (t_point){
			self->bg->width / 2 - self->icons[i]->width / 2,
			self->bg->height / 2 - self->icons[i]->height / 2};
		if (mlx_image_to_window(mlx, self->icons[i], pt.x, pt.y) == -1)
			cbd_terminate(CBD_EGENERIC);
		mlx_set_instance_depth(&self->icons[i]->instances[0],
				CBD_Z_SCREEN_OVERLAY_ICON);
		++i;
	}
	
}
