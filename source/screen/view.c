/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 17:36:30 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/29 18:36:16 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_error.h"
#include "cbd_screen.h"
#include "MLX42_ext.h"

void	view_init(t_view *self, t_assets const *assets, mlx_t *mlx)
{
	self->horizon = CBD_VIEW_H_DFL / 2;
	self->ceiling = mlx_new_image(mlx, CBD_VIEW_W_DFL, CBD_BOX_H_DFL);
	if (self->ceiling == NULL)
		cbd_terminate(CBD_EGENERIC);
	self->floor = mlx_new_image(mlx, CBD_VIEW_W_DFL, CBD_BOX_H_DFL);
	if (self->floor == NULL)
		cbd_terminate(CBD_EGENERIC);
	self->scene = mlx_new_image(mlx, CBD_VIEW_W_DFL, CBD_VIEW_H_DFL);
	if (self->scene == NULL)
		cbd_terminate(CBD_EGENERIC);
	//mlx_image_fill(self->ceiling, assets->ceiling_rgba);
	//mlx_image_fill(self->floor, assets->floor_rgba);
	self->wall_height = CBD_WALL_H_DFL;
}

void	view_deinit(t_view *self, mlx_t *mlx)
{
	mlx_delete_image(mlx, self->scene);
	mlx_delete_image(mlx, self->floor);
	mlx_delete_image(mlx, self->ceiling);
}

void	view_draw(t_view *self, t_point pt, mlx_t *mlx)
{
	int const	ceiling_y = pt.y - CBD_VIEW_Z_MARGIN;
	int const	floor_y = pt.y + CBD_VIEW_H_DFL_2;

	if (mlx_image_to_window(mlx, self->ceiling, pt.x, ceiling_y) == -1)
		cbd_terminate(CBD_EGENERIC);
	if (mlx_image_to_window(mlx, self->floor, pt.x, floor_y) == -1)
		cbd_terminate(CBD_EGENERIC);
	if (mlx_image_to_window(mlx, self->scene, pt.x, pt.y) == -1)
		cbd_terminate(CBD_EGENERIC);
	mlx_set_instance_depth(&self->ceiling->instances[0], CBD_Z_VIEW_BG);
	mlx_set_instance_depth(&self->floor->instances[0], CBD_Z_VIEW_BG);
	mlx_set_instance_depth(&self->scene->instances[0], CBD_Z_VIEW_SCENE);
}
