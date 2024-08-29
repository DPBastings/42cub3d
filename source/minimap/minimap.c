/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:04:28 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 16:39:19 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_map.h"
#include "cbd_error.h"

void	minimap_init(t_game *game, t_minimap *self,
			t_map const *map, mlx_t *mlx)
{
	self->img = mlx_new_image(mlx, CBD_MINIMAP_W_PX, CBD_MINIMAP_H_PX);
	if (self->img == NULL)
		cbd_mlx_terminate(game, CBD_EGENERIC);
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
	if (!mlx)
		return ;
	if (self->img)
		mlx_delete_image(mlx, self->img);
}
