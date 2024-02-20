/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:04:28 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 18:17:14 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_map.h"
#include "cbd_error.h"

void	minimap_init(t_minimap *self, t_map const *map, mlx_t *mlx)
{
	self->img = mlx_new_image(mlx, CBD_MINIMAP_W_PX, CBD_MINIMAP_H_PX);
	if (self->img == NULL)
		cbd_terminate(CBD_EGENERIC);
	self->viewport_max = (t_dpoint){
		map->x_size - CBD_MINIMAP_W_M / 2,
		map->y_size - CBD_MINIMAP_H_M / 2};
}

void	minimap_draw(t_minimap *self, t_point pos, mlx_t *mlx)
{
	mlx_image_to_window(mlx, self->img, pos.x, pos.y);
	mlx_set_instance_depth(&self->img->instances[0], CBD_Z_MINIMAP);
}

void	minimap_deinit(t_minimap *self, mlx_t *mlx)
{
	mlx_delete_image(mlx, self->img);
}
