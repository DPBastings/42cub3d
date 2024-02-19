/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 17:36:30 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 17:55:46 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_screen.h"
#include "MLX42_ext.h"

void	view_init(t_view *self, t_assets const *assets, mlx_t *mlx)
{
	self->horizon = CBD_VIEW_HEIGHT_DFL / 2;
	self->ceiling = mlx_new_image(mlx, CBD_VIEW_WIDTH_DFL, CBD_BOX_HEIGHT);
	mlx_image_fill(self->ceiling, assets->ceiling_rgba);
	self->floor = mlx_new_image(mlx, CBD_VIEW_WIDTH_DFL, CBD_BOX_HEIGHT);
	mlx_image_fill(self->floor, assets->floor_rgba);
	self->scene = mlx_new_image(mlx, CBD_VIEW_WIDTH_DFL, CBD_VIEW_HEIGHT_DFL);
	self->wall_height = CBD_WALL_HEIGHT_DFL;
}

void	view_deinit(t_view *self, mlx_t *mlx)
{
	mlx_delete_image(mlx, self->scene);
	mlx_delete_image(mlx, self->floor);
	mlx_delete_image(mlx, self->ceiling);
}

void	view_draw(t_view *self, t_point pt, mlx_t *mlx)
{
	mlx_image_to_window(mlx, self->ceiling, pt.x, pt.y - CBD_VIEW_Z_MARGIN);
	mlx_set_instance_depth(&self->ceiling->instances[0], 0);
	mlx_image_to_window(mlx, self->floor, pt.x, pt.y + CBD_VIEW_HEIGHT_DFL_2);
	mlx_set_instance_depth(&self->floor->instances[0], 0);
	mlx_image_to_window(mlx, self->scene, pt.x, pt.y);
	mlx_set_instance_depth(&self->scene->instances[0], 1);
}
